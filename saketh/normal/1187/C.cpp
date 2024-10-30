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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    struct range { int l, r; };
    vector<range> sorted, nsorted;

    F0R (i, M) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) sorted.pb({ l-1, r });
        else nsorted.pb({ l-1, r });
    }

    vb leq(N - 1);

    for (auto& [l, r] : sorted) {
        FOR (i, l, r - 1) leq[i] = true;
    }

    for (auto& [l, r] : nsorted) {
        bool ok = false;
        FOR (i, l, r - 1) ok |= !leq[i];
        if (!ok) { cout << "NO\n"; return 0; }
    }

    vi res(N);
    int tl = 1;

    F0Rd (i, N) {
        if (i < N - 1 && !leq[i]) tl++;
        res[i] = tl;
    }

    cout << "YES\n";
    F0R (i, N) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";

    return 0;
}