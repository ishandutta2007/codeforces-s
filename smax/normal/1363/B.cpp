#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int pref[1005], suff[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();

        for (int i=0; i<n; i++)
            pref[i] = (i > 0 ? pref[i-1] : 0) + (s[i] == '1');
        for (int i=n-1; i>=0; i--)
            suff[i] = (i < n - 1 ? suff[i+1] : 0) + (s[i] == '1');

        int ret = min(suff[0], n - suff[0]);
        for (int i=0; i<n; i++)
            ret = min({ret, pref[i] + (i < n - 1 ? (n - i - 1) - suff[i+1] : 0), i + 1 - pref[i] + (i < n - 1 ? suff[i+1] : 0)});

        cout << ret << "\n";
    }

    return 0;
}