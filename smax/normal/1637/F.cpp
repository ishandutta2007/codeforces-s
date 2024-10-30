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

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i=0; i<n; i++)
        cin >> h[i];
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> smx(n);

    auto dfs = [&] (auto &self, int u, int p) -> int {
        for (int v : adj[u])
            if (v != p)
                smx[u] = max(smx[u], max(h[v], self(self, v, u)));
        return smx[u];
    };

    int r = int(max_element(h.begin(), h.end()) - h.begin());
    dfs(dfs, r, -1);
    long long ret = 0;

    auto solve = [&] (auto &self, int u, int p) -> int {
        int mx = 0;
        for (int v : adj[u])
            if (v != p)
                mx = max(mx, self(self, v, u));
        if (h[u] > smx[u])
            ret += max(h[u] - mx, 0);
        return max(mx, h[u]);
    };

    int mx1 = 0, mx2 = 0;
    for (int v : adj[r]) {
        int cur = solve(solve, v, r);
        if (cur > mx1) {
            mx2 = mx1;
            mx1 = cur;
        } else if (cur > mx2) {
            mx2 = cur;
        }
    }
    cout << ret + max(h[r] - mx1, 0) + max(h[r] - mx2, 0) << "\n";

    return 0;
}