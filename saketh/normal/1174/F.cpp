#include <bits/stdc++.h>
using namespace std;

// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush

namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::iterator find(vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }
}
using namespace __algorithm;

struct monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))monostate& ms) { return os; }
} ms;

template<typename W=monostate> struct wedge {
    int u, v, i; W w;
    wedge<W>(int _u=-1, int _v=-1, int _i=-1) : u(_u), v(_v), i(_i) {}
    int operator[](int loc) const { return u ^ v ^ loc; }
    friend void re(wedge& e) { re(e.u, e.v, e.w); --e.u, --e.v; }
    friend void pr(const wedge& e) { pr(e.u, "<-", e.w, "->", e.v); }
};

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}


vvi adj;

int secret;
vi dist, step;
void calc(int loc, int par) {
    for (int nbr : adj[loc]) if (nbr != par) {
        dist[nbr] = dist[loc] + 1;
        step[nbr] = loc;
        calc(nbr, loc);
    }
}

bool LOCAL = false;

int QQ = 0;

int q1(int u) {
    ++QQ;
    if (LOCAL) return dist[u];

    ps('d', u+1); cout << flush;
    int d; re(d);
    assert(d != -1);
    return d;
}

int q2(int u) {
    ++QQ;
    if (LOCAL) return step[u];

    ps('s', u+1); cout << flush;
    int v; re(v);
    assert(v != -1);
    return v-1;
}

void fin(int a) {
    if (LOCAL) assert(a == secret);
    ps("!", a + 1);
    exit(0);
}

const int MAXN = 2e5 + 1;
bool erase[MAXN];
int tsz[MAXN], depth[MAXN];

void dfs(int loc, int par) {
    tsz[loc] = 1;
    for (int nbr : adj[loc]) if (nbr != par && !erase[nbr]) {
        depth[nbr] = depth[loc] + 1;
        dfs(nbr, loc);
        tsz[loc] += tsz[nbr];
    }
}

int NN;

void go(int root, int rdist, bool first = false) {
    assert(!erase[root]);

    if (QQ + rdist <= 36) {
        F0R (d, rdist) root = q2(root);
        fin(root);
    }

    memset(tsz, 0, sizeof(tsz));
    memset(depth, 0, sizeof(depth));

    dfs(root, root);

    if (!first) {
        if (tsz[root] * 2 > NN) { exit(420); }
        NN = tsz[root];
    }

    pii ctr{tsz[root], root};
    F0R (i, sz(adj)) if (tsz[i] * 2 >= tsz[root])
        ckmin(ctr, {tsz[i], i});

    int cdist = ctr.s == root ? rdist : q1(ctr.s);
    if (cdist == rdist - depth[ctr.s]) {
        if (cdist == 0) fin(ctr.s);
        int nroot = q2(ctr.s);
        if (nroot >= sz(adj) || nroot < 0) exit(24);
        if (erase[nroot]) exit(23);
        erase[ctr.s] = true;
        if (tsz[nroot] * 2 >= tsz[root]) exit(6);
        go(nroot, cdist - 1);
    } else {
        if (ctr.s == root) exit(2016);
        erase[ctr.s] = true;
        go(root, rdist);
    }
}

int main() {
    setIO();

    int N; re(N);
    NN = N;

    adj.resz(N);
    F0R (i, N-1) {
        int u, v; re(u, v); --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (LOCAL) {
        secret = rng() % N;
        dist.resz(N);
        step.resz(N);
        calc(secret, secret);
    }

    go(0, q1(0), true);

    return 0;
}