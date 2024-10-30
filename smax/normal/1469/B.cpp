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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> r(n);
        for (int i=0; i<n; i++)
            cin >> r[i];
        int m;
        cin >> m;
        vector<int> c(m);
        for (int i=0; i<m; i++)
            cin >> c[i];

        int ret = 0, prefR = 0, prefC = 0;
        for (int j=0; j<m; j++) {
            prefC += c[j];
            ret = max(ret, prefC);
        }
        for (int i=0; i<n; i++) {
            prefR += r[i];
            prefC = 0;
            ret = max(ret, prefR);
            for (int j=0; j<m; j++) {
                prefC += c[j];
                ret = max(ret, prefR + prefC);
            }
        }
        cout << ret << "\n";
    }

    return 0;
}