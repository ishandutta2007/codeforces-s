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
        int c1 = 0, c2 = 0;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            if (a == 1) c1++;
            else c2++;
        }
        bool ok = false;
        for (int i=0; i<=c1; i++)
            if ((c1 + 2 * c2 - 2 * i) % 4 == 0 && 0 <= (c1 + 2 * c2 - 2 * i) / 4 && (c1 + 2 * c2 - 2 * i) / 4 <= c2) {
                ok = true;
                break;
            }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}