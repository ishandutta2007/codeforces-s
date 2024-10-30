#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        int ret = 0;
        vector<bool> vis(n);
        for (int i=0; i<n; i++)
            if (!vis[i]) {
                int u = i, steps = -1e9;
                while (!vis[u]) {
                    vis[u] = true;
                    if (a[u] == 0) {
                        DEBUG(t, u, steps);
                        ret = max(ret, steps - 1);
                        steps = 0;
                    }
                    u = (u + d) % n;
                    steps++;
                }
                if (steps < 0) {
                    ret = -1;
                    break;
                }
                while (a[u] == 1) {
                    u = (u + d) % n;
                    steps++;
                }
                ret = max(ret, steps - 1);
            }
        cout << ret << "\n";
    }

    return 0;
}