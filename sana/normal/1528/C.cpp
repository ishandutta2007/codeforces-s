#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#if 0
    #include <bits/extc++.h>
    using namespace __gnu_pbds;

    template<class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; F0R(i,SZ) res += char('0'+b[i]); return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { bool fst = 1; str res = "{"; for (const auto& x: v) {if (!fst) res += ", ";	fst = 0; res += ts(x);}	res += "}"; return res;}
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.first)+", "+ts(p.second)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }

int myrand(int l, int r) { return uniform_int_distribution(l, r)(rng); }

#endif

vi intime, outime;
vector<vi> g1;
vector<vi> g2;
int tim;

set< pii > inters;

void dfs2(int v) {
    intime[v] = tim++;
    for (int x : g2[v]) {
        dfs2(x);
    }
    outime[v] = tim;
}

int dfs(int v) {
    auto it = inters.lower_bound( {intime[v], 0} );

    int erased = -1;
    if (it != inters.begin()) {
        it = prev(it);
        if (it->second < 0) {
            erased = -it->second - 1;
            inters.erase({intime[erased], -(erased+1)});
            inters.erase({outime[erased] - 1, erased+1});
        }
    }

    it = inters.lower_bound( {intime[v], 0} );
    if (it == inters.end() || it->first >= outime[v]) {
        inters.insert({intime[v], -(v+1)});
        inters.insert({outime[v] - 1, v+1});
    }
    
    int r = inters.size() / 2;
    dbg(intime[v], outime[v]);
    dbg(v, inters);

    for (int x : g1[v]) r = max(r, dfs(x));

    inters.erase({intime[v], -(v+1)});
    inters.erase({outime[v] - 1, v+1});
    if (erased != -1) {
        inters.insert({intime[erased], -(erased+1)});
        inters.insert({outime[erased] - 1, erased+1});
    }
    
    return r;
}

void solve() {
    int n; cin >> n;

    g1 = vector<vi>(n);
    g2 = vector<vi>(n);
    intime = vi(n);
    outime = vi(n);

    for (int i = 1; i < n; i++) {
        int u; cin >> u; u--;
        g1[u].push_back(i);
    }
    for (int i = 1; i < n; i++) {
        int u; cin >> u; u--;
        g2[u].push_back(i);
    }

    tim = 0;
    dfs2(0);

    cout << dfs(0) << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    for (cin >> t; t; t--) solve();
    return 0;
}