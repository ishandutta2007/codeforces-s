//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

template <class T>
V<T> make_vec(size_t a) {
    return V<T>(a);
}

template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T>
void mkuni(vector<T>& v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
}

template <class T>
vector<int> sort_by(const vector<T>& v) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) { return v[i] < v[j]; });
    return res;
}

template <class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
    is >> p.first >> p.second;
    return is;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) {
        is >> x;
    }
    return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

template <class T>
void scan(vector<T>& v, T offset = T(0)) {
    for (auto& x : v) {
        cin >> x;
        x += offset;
    }
}

template <class T>
void print(T x, int suc = 1) {
    cout << x;
    if (suc == 1)
        cout << "\n";
    else if (suc == 2)
        cout << " ";
}

template <class T>
void print(const vector<T>& v, int suc = 1) {
    for (int i = 0; i < v.size(); ++i)
        print(v[i], i == int(v.size()) - 1 ? suc : 2);
}

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;

template <class T>
class Edge {
   public:
    int from, to, idx;
    T cost;

    Edge() = default;
    Edge(int from, int to, T cost = T(1), int idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {}
    operator int() const { return to; }

    bool operator<(const Edge& e) const { return cost < e.cost; }
};

template <class T>
class Graph {
   public:
    using E = Edge<T>;
    vector<vector<E>> g;
    vector<E> edges;
    int es;

    Graph() {}
    Graph(int n) : g(n), edges(0), es(0){};

    int size() const { return g.size(); }

    virtual void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }

    virtual void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    inline vector<E>& operator[](const int& k) { return g[k]; }

    inline const vector<E>& operator[](const int& k) const { return g[k]; }

    void read(int M, int offset = -1, bool directed = false,
              bool weighted = false) {
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a += offset;
            b += offset;
            T c = T(1);
            if (weighted) cin >> c;
            edges.emplace_back(a, b, c);
            if (directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }
};

template <class T>
V<T> bfs(const Graph<T>& g, int s = 0) {
    const T inf = numeric_limits<T>::max() / 2;
    int n = g.size();

    V<T> ds(n, inf);
    using P = pair<T, int>;
    queue<int> que;
    que.push(s);
    ds[s] = 0;

    while (!que.empty()) {
        auto v = que.front();
        que.pop();
        for (auto e : g[v]) {
            T nx = ds[v] + 1;
            if (ds[e.to] > nx) {
                ds[e.to] = nx;
                que.push(e.to);
            }
        }
    }
    for (auto& x : ds)
        if (x == inf) x = -1;
    return ds;
}

// must be optimized
template <class T>
V<T> bfs01(const Graph<T>& g, int s = 0) {
    const T inf = numeric_limits<T>::max() / 2;
    int n = g.size();

    V<T> ds(n, inf);
    using P = pair<T, int>;
    deque<int> que;
    que.push_back(s);
    ds[s] = 0;

    while (!que.empty()) {
        auto v = que.front();
        que.pop_front();
        for (auto e : g[v]) {
            T nx = ds[v] + e.cost;
            if (ds[e.to] > nx) {
                ds[e.to] = nx;
                if (e.cost == 0) {
                    que.push_front(e.to);
                } else {
                    que.push_back(e.to);
                }
            }
        }
    }
    for (auto& x : ds)
        if (x == inf) x = -1;
    return ds;
}

template <class T>
V<T> dijkstra(const Graph<T>& g, int s = 0) {
    const T inf = numeric_limits<T>::max() / 2;
    int n = g.size();

    V<T> ds(n, inf);
    using P = pair<T, int>;
    priority_queue<P, V<P>, greater<P>> que;
    que.emplace(0, s);
    ds[s] = 0;
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        int v = p.se;
        if (ds[v] < p.fi) continue;
        for (auto e : g[v]) {
            T nx = ds[v] + e.cost;
            if (ds[e.to] > nx) {
                ds[e.to] = nx;
                que.emplace(nx, e.to);
            }
        }
    }
    for (auto& x : ds)
        if (x == inf) x = -1;
    return ds;
}

void slv() {
    int n;
    cin >> n;
    V<int> a(n);
    scan(a, -1);

    VV<int> vp(n);
    rep(i, n) vp[a[i]].pb(i);

    Graph<int> g(n);

    V<int> psum(n + 10);

    rep(i, n) if (SZ(vp[i])) {
        int l = vp[i][0];
        int r = vp[i].back();
        psum[l + 1]++;
        psum[r + 1]--;
        g.add_directed_edge(l, r, 1);
    }

    rep(i, n + 3) psum[i + 1] += psum[i];

    using T = int;
    const int inf = numeric_limits<int>::max() / 2;

    V<int> vs, gl;

    rep(i, n) {
        if (psum[i] == 0 && psum[i + 1] > 0) {
            vs.pb(i);
            int j = i;
            while (psum[j + 1] > 0) j++;
            gl.pb(j);
            for (int k = i; k < j; ++k) {
                g.add_directed_edge(k + 1, k, 0);
            }
        }
    }

    V<int> ds(n, inf);
    using P = pair<int, int>;
    deque<int> que;
    for (int s : vs) {
        que.push_back(s);
        ds[s] = 0;
    }

    while (!que.empty()) {
        auto v = que.front();
        que.pop_front();
        for (auto e : g[v]) {
            T nx = ds[v] + e.cost;
            if (ds[e.to] > nx) {
                ds[e.to] = nx;
                if (e.cost == 0) {
                    que.push_front(e.to);
                } else {
                    que.push_back(e.to);
                }
            }
        }
    }
    for (auto& x : ds)
        if (x == inf) x = -1;

    ll ans = 0;
    for (int v : vs) ans -= v;
    for (int v : gl) {
        ans += v;
        ans -= ds[v];
    }
    debug(ds);
    print(ans);
}

int main() {
    int cases = 1;
    // cin >> cases;
    rep(i, cases) slv();

    return 0;
}