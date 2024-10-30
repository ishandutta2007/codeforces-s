#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cnt(2);
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        if (cnt[1] <= n / 2) {
            cout << n - cnt[1] << "\n";
            for (int i=0; i<n-cnt[1]; i++)
                cout << "0 ";
            cout << "\n";
        } else {
            cout << n - cnt[0] - cnt[1] % 2 << "\n";
            for (int i=0; i<n-cnt[0]-cnt[1]%2; i++)
                cout << "1 ";
            cout << "\n";
        }
    }

    return 0;
}