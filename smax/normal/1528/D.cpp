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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    // O(n * (n^2 + m))
    // Use O(n^2) Dijkstra
    for (int i=0; i<n; i++) {
        vector<int> dist(n, INF);
        vector<bool> vis(n);
        dist[i] = 0;
        for (int rep=0; rep<n-1; rep++) {
            int u = -1;
            for (int v=0; v<n; v++)
                if (!vis[v] && (u == -1 || dist[v] < dist[u]))
                    u = v;
            assert(u != -1);
            vis[u] = true;
            vector<int> cur(n, INF);
            int mn = INF;
            for (auto [v, c] : adj[u]) {
                int t = (v + dist[u]) % n;
                cur[t] = c;
                mn = min(mn, n - t + c);
            }
            for (int v=0; v<n; v++) {
                mn = min(mn, cur[v]);
                dist[v] = min(dist[v], dist[u] + mn);
                mn++;
            }
        }
        for (int v=0; v<n; v++)
            cout << dist[v] << " ";
        cout << "\n";
    }

    return 0;
}