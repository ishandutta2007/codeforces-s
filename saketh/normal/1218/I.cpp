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
    template<class T> void pr(const deque<T>& x);
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
    template<class T> void pr(const deque<T>& x) { prContain(x); }
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
    template<typename C, typename T, typename OP> vector<T> prefixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0R (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
    }
    template<typename C, typename T, typename OP> vector<T> suffixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0Rd (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;
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
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

// tarjan {{{
tuple<int, vi> strongly_connected_components(const vvi& graph) {
    const int N = graph.size();
    int C = 0, V = 0, top = 0;
    vi comp(N, -1), inx(N, -1), stack(N + 1, -1);

    auto tarjan = [&](auto&& self, int loc) -> int {
        stack[top++] = loc;
        int low = inx[loc] = V++;
        for (int nbr : graph[loc]) {
            if (inx[nbr] == -1) low = min(low, self(self, nbr));
            else if (comp[nbr] == -1) low = min(low, inx[nbr]);
        }
        if (low == inx[loc]) {
            while (stack[top] != loc)
                comp[stack[--top]] = C;
            C++;
        }
        return low;
    };

    for (int i = 0; i < N; i++) {
        if (inx[i] == -1)
            tarjan(tarjan, i);
    }
    return { C, comp };
}
// }}}
// two-sat {{{
struct two_sat {
    vvi graph;
    two_sat() {}

    inline int neg(int a) { return a^1; }

    void implies(int a, int b) {
        if (a < 0 || b < 0) return;
        graph[a].pb(b);
        graph[neg(b)].pb(neg(a));
    }

    void assign(int a, int v) {
        if (v) implies(neg(a), a);
        else implies(a, neg(a));
    }
    void equal(int a, int b) {
        implies(a, b);
        implies(neg(a), neg(b));
    }
    void not_equal(int a, int b) {
        implies(a, neg(b));
        implies(neg(a), b);
    }
    void at_most_one(int a, int b) {
        implies(a, neg(b)); // contrapositive is automatic
    }
    void at_least_one(int a, int b) {
        implies(neg(a), b); // contrapositive is automatic
    }

    int new_var() {
        graph.pb({});
        graph.pb({});
        return sz(graph) - 1;
    }

    int make_or(int a, int b) {
        if (a < 0) return b;
        if (b < 0) return a;
        int v = new_var();
        implies(a, v);
        implies(b, v);
        return v;
    }

    int make_and(int a, int b) {
        if (a < 0) return b;
        if (b < 0) return a;
        int v = new_var();
        implies(v, a);
        implies(v, b);
        return v;
    }

    vb solve() {
        int C; vi comp; tie(C, comp) = strongly_connected_components(graph);
        vb res(sz(graph));
        for (int v = 0; v < sz(res); v++) {
            if (comp[v] == comp[neg(v)]) return {};
            res[v] = comp[v] < comp[neg(v)];
        }
        return res;
    }
};
// }}}

int main() {
    setIO();

    int N; re(N); vs a(N), b(N); re(a, b); string m; re(m);

    two_sat ts;
    vi rows(N); F0R (i, N) rows[i] = ts.new_var();
    vi cols(N); F0R (i, N) cols[i] = ts.new_var();

    F0R (i, N) F0R (j, N) {
        bool fl = b[i][j] != a[i][j];
        bool r = m[j] == '1';
        bool c = m[i] == '1';

        if (r && c) {
            if (fl) ts.not_equal(rows[i], cols[j]);
            else ts.equal(rows[i], cols[j]);
        } else if (r) {
            ts.assign(rows[i], fl);
        } else if (c) {
            ts.assign(cols[j], fl);
        } else if (fl) {
            ps(-1); return 0;
        }
    }

    vb res = ts.solve();
    if (!sz(res)) { ps(-1); return 0; }

    vi moves;
    F0R (i, N) if (res[rows[i]]) moves.pb(i);
    F0R (i, N) if (res[cols[i]]) moves.pb(i + N);
    ps(sz(moves));
    trav (mv, moves) {
        if (mv < N) ps("row", mv);
        else ps("col", mv-N);
    }

    return 0;
}