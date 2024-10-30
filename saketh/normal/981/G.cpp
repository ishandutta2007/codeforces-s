#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define F0R(i, a)       for (int i = 0; i < (a); i++)
#define FORd(i, a, b)   for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a)      for (int i = (a)-1; i >= 0; i--)
#define trav(a, x)      for (auto& a : x)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template <size_t I> struct index_t {};
#define _i(i, v) const index_t<i> v{}
_i(0, _0); _i(1, _1); _i(2, _2); _i(3, _3); _i(4, _4);
template<typename... T> struct tp {
    std::tuple<T...> elts;
    tp() {}
    tp(std::tuple<T...> _t) : elts(_t) {}
    template<typename T1, typename... Ts> tp(T1 t1, Ts... ts) : elts(t1, ts...) {}
    template <size_t I> decltype(auto) operator[](index_t<I>) {
        return get<I>(this->elts);
    }
    template <size_t I> decltype(auto) operator[](index_t<I>) const {
        return get<I>(this->elts);
    }
    friend bool operator <(const tp& a, const tp& b) { return a.elts < b.elts; }
};

namespace __input {
    template<typename T, size_t... I> void read_tuple(istream& i, T& t, index_sequence<I...>) {
        ((i >> get<I>(t)), ...);
    }
    template<typename... T> istream& operator>>(istream& i, tp<T...>& t) {
        read_tuple(i, t.elts, index_sequence_for<T...>{}); return i;
    }
    template<typename T1, typename T2> istream& operator >>(istream& i, pair<T1, T2>& p) {
        i >> p.first >> p.second; return i;
    }
    template<typename T, size_t N> istream& operator >>(istream& i, array<T, N>& v) {
        for (auto& e : v) { i >> e; } return i;
    }
    template<typename T> istream& operator >>(istream& i, vector<T>& v) {
        for (auto& e : v) { i >> e; } return i;
    }
}
using namespace __input;

namespace __output {
    template<typename T, size_t... I> void write_tuple(ostream& o, const T& t, index_sequence<I...>) {
        o << "("; ((o << (I ? ", " : "") << get<I>(t)), ...); o << ")";
    }
    template<typename... T> ostream& operator<<(ostream& o, const tp<T...>& t) {
        write_tuple(o, t.elts, index_sequence_for<T...>{}); return o;
    }
    template<typename T1, typename T2> ostream& operator<<(ostream& o, const pair<T1, T2>& t) {
        return o << "(" << t.first << ", " << t.second << ")";
    }
    template<typename T, size_t N> ostream& operator<<(ostream& o, const array<T, N>& a) {
        o << "["; for (int i = 0; i < N; i++) { if (i) o << ", "; o << a[i]; } return o << "]";
    }
    template<typename T> ostream& operator<<(ostream& o, const vector<T>& v) {
        o << "["; for (int i = 0; i < sz(v); i++) { if (i) o << ", "; o << v[i]; } return o << "]";
    }
}
using namespace __output;

template<int MOD> struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(ll _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend istream& operator >> (istream& i, modnum& n) { ll v; i >> v; n = modnum(v); return i; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = int(ll(v) * ll(o.v) % MOD); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(ll e) const {
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    modnum inv() const {
        int g = MOD, x = 0, y = 1;
        for (int r = v; r != 0; ) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        assert(g == 1);
        assert(y == MOD || y == -MOD);
        return x < 0 ? x + MOD : x;
    }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }

    static int totient() {
        int tot = MOD, tmp = MOD;
        for (int p = 2; p * p <= tmp; p++) if (tmp % p == 0) {
            tot = tot / p * (p - 1);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot = tot / tmp * (tmp - 1);
        return tot;
    }

    static int primitive_root() {
        if (MOD == 1) return 0;
        if (MOD == 2) return 1;

        int tot = totient(), tmp = tot;
        vi tot_pr;
        for (int p = 2; p * p <= tmp; p++) if (tot % p == 0) {
            tot_pr.push_back(p);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot_pr.push_back(tmp);

        for (int r = 2; r < MOD; r++) if (__gcd(r, MOD) == 1) {
            bool root = true;
            for (int p : tot_pr) root &= modnum(r).pow(tot / p) != 1;
            if (root) return r;
        }
        assert(false);
    }

    static modnum generator() { static modnum g = primitive_root(); return g; }
    static int discrete_log(modnum v) {
        static const int M = ceil(sqrt(MOD));
        static unordered_map<int, int> table;
        if (table.empty()) {
            modnum e = 1;
            for (int i = 0; i < M; i++) { table[e.v] = i; e *= generator(); }
        }
        static modnum f = generator().pow(totient() - M);

        for (int i = 0; i < M; i++) {
            if (table.count(v.v)) return table[v.v] + i * M;
            v *= f;
        }
        assert(false);
    }

    static modnum fact(int n) {
        static vector<modnum<MOD>> fact = { 1 };
        for (assert(n >= 0); fact.size() <= n; )
            fact.push_back(fact.back() * fact.size());
        return fact[n];
    }

    static modnum finv(int n) {
        static vector<modnum<MOD>> finv = { 1 };
        for (assert(n >= 0); finv.size() <= n; )
            finv.push_back(finv.back() / finv.size());
        return finv[n];
    }

    static modnum ncr(int n, int r) {
        if (r < 0 || n < r) return 0;
        return fact(n) * finv(r) * finv(n - r);
    }
};

template<typename T, typename U, bool PROP = true> struct segment_tree_lazy {
    int S;
    vector<T> table;
    vb has; vector<U> ops;

    segment_tree_lazy(int _S) : S(_S) {
        table.resize(2 * S), has.resize(S), ops.resize(S);
    }

    segment_tree_lazy(auto begin, auto end) : segment_tree_lazy(distance(begin, end)) {
        copy(begin, end, table.begin() + S);
        for (int i = S - 1; i > 0; i--)
            table[i] = table[2 * i] + table[2 * i + 1];
    }

    void apply(int i, const U &op) {
        table[i] = op(table[i]);
        if (i < S) has[i] = true, ops[i] = op(ops[i]);
    }

    void rebuild(int i) {
        for (i /= 2; i; i /= 2)
            table[i] = ops[i](table[2 * i] + table[2 * i + 1]);
    }

    void propagate(int i) {
        for (int j = 31 - __builtin_clz(i); j > 0; j--) {
            if (int k = i >> j; has[k]) {
                apply(2 * k, ops[k]);
                apply(2 * k + 1, ops[k]);
                has[k] = false, ops[k] = U{};
            }
        }
    }

    void replace(int i, T v) {
        if (PROP) propagate(i + S);
        table[i + S] = v;
        rebuild(i + S);
    }

    void operator()(int i, int j, U op) {
        i += S, j += S;
        if (PROP) propagate(i), propagate(j - 1);
        for (int l = i, r = j; l < r; l /= 2, r /= 2) {
            if (l&1) apply(l++, op);
            if (r&1) apply(--r, op);
        }
        rebuild(i), rebuild(j - 1);
    }

    T operator()(int i, int j) {
        i += S, j += S;
        if (PROP) propagate(i), propagate(j - 1);
        T left{}, right{};
        for (; i < j; i /= 2, j /= 2) {
            if (i&1) left = left + table[i++];
            if (j&1) right = table[--j] + right;
        }
        return left + right;
    }
    T operator()(int i) { return *this(i, i+1); }
};

using mn = modnum<int(998244353)>;

struct node {
    mn v; int w;
    node(mn _v = 0, int _w = 0) : v(_v), w(_w) {}
    node operator+(const node& o) { return node(v + o.v, w + o.w); }
};

struct upd {
    mn a, b;
    upd(mn _a = 1, mn _b = 0) : a(_a), b(_b) {}
    upd operator()(const upd& o) const {
        return upd(a * o.a, b + a * o.b);
    }
    node operator()(const node& v) const {
        return node(a * v.v + b * v.w, v.w);
    }
};

struct union_find {
    struct node {
        int par, rank, emin;
        node(int id = 0) : par(id), rank(0), emin(id) {}
        void operator +=(const node& o) {
            if (rank == o.rank) rank++;
            ckmin(emin, o.emin);
        }
    };

    vector<node> uf;
    union_find(int N = 0) : uf(N) {
        for (int i = 0; i < N; i++) uf[i] = node(i);
    }

    int rep(int i) {
        if (i != uf[i].par)
            uf[i].par = rep(uf[i].par);
        return uf[i].par;
    }

    bool unio(int a, int b) {
        a = rep(a), b = rep(b);
        if (a == b) return false;
        if (uf[a].rank < uf[b].rank) swap(a, b);
        uf[a] += uf[b];
        uf[b].par = a;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vvi sec(N);

    struct query { int t, l, r, x; };
    vector<query> queries(Q);
    for (auto &[t, l, r, x] : queries) {
        cin >> t;
        if (t == 1) {
            cin >> l >> r >> x;
            x--, l--, r--;
            sec[x].pb(l);
            sec[x].pb(r + 1);
        }
        else {
            cin >> l >> r;
            l--, r--;
        }
    }

    vector<union_find> uf(N);
    vector<vb> has(N);

    F0R (x, N) {
        sort(all(sec[x]));
        sec[x].erase(unique(all(sec[x])), sec[x].end());

        uf[x] = union_find(sz(sec[x]));
        F0R (i, sz(sec[x])) assert(uf[x].rep(i) == i);
        has[x].resize(sz(sec[x]));
    }

    vector<node> leaves(N);
    F0R (i, N) leaves[i].w = 1;
    segment_tree_lazy<node, upd> st(all(leaves));

    for (auto &[t, l, r, x] : queries) {
        if (t == 1) {
            int i = lb(all(sec[x]), l) - sec[x].begin();
            int j = ub(all(sec[x]), r) - sec[x].begin();
            while (j > i) {
                if (!has[x][--j]) {
                    int sk = j;
                    has[x][j] = true;

                    if (j+1 < sz(has[x]) && has[x][j+1]) uf[x].unio(j, j + 1);
                    while (sk > i && !has[x][sk - 1]) {
                        has[x][--sk] = true;
                        uf[x].unio(sk, sk + 1);
                    }
                    if (sk && has[x][sk-1]) uf[x].unio(sk - 1, sk);

                    st(sec[x][sk], sec[x][j+1], upd(1, 1));
                    j = sk;
                } else {
                    int sk = max(i, uf[x].uf[uf[x].rep(j)].emin);
                    st(sec[x][sk], sec[x][j+1], upd(2, 0));
                    j = sk;
                }
            }
        } else {
            cout << st(l, r + 1).v << "\n";
        }
    }

    return 0;
}