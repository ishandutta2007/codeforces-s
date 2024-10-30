#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define pd __gnu_pbds
#define st first
#define nd second
#define all(x) (x).begin(), (x).end()
 
using namespace std;
using namespace placeholders;
 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T> using il = initializer_list<T>;
 
template <class T> inline void mini(T &l, T r){l = min(l, r);}
template <class T> inline void maxi(T &l, T r){l = max(l, r);}
 
template <class T> void _dbg(const char *sdbg, T &&h){cerr << sdbg << "=" << h << "\n";}
template <class T, class ...R> void _dbg(const char *sdbg, T h, R... a){
	while (*sdbg != ','){cerr << *sdbg++;} cerr << "=" << h << ","; _dbg(sdbg + 1, a...);}
template <class L, class R> ostream &operator <<(ostream &os, const pair<L, R> &P){
	return os << "(" << P.st << "," << P.nd << ")";}
template <class T> ostream &operator <<(ostream &os, const vector<T> &v){
	os << "["; for (auto x: v) os << x << ","; return os << "]";}
template <class IT, class V = vector<typename iterator_traits<IT>::value_type>> V gr(IT b, IT e){
	return V(b, e);}
template <class T, class c = decltype(T().begin()), typename enable_if<!is_same<T, string>::value>::type* = nullptr> ostream &operator <<(ostream &os, T &v){
	return os << gr(v.begin(), v.end());}
template <class T, int I, int N, typename enable_if<I == N, T>::type* = nullptr> void TuplePrint(ostream &os, T val){
	os << get<N>(val);}
template <class T, int I, int N, typename enable_if<I < N, T>::type* = nullptr> void TuplePrint(ostream &os, T val){
	os << get<I>(val) << ","; TuplePrint<T, I + 1, N>(os, val);}
template <class... Ts> ostream &operator<<(ostream &os, tuple<Ts...> t){
	os << "("; TuplePrint<tuple<Ts...>, 0, sizeof...(Ts) - 1>(os, t); return os << ")";}
 
#ifdef SFIC
#define eput(...) do{cerr << __LINE__;_dbg("\t| "#__VA_ARGS__, __VA_ARGS__);}while(0)
#else
#define eput(...) 218
#endif
 
//pd::priority_queue<int, less<int>, pairing_heap_tag>
//pd::tree<int, int, less<int>, pd::rb_tree_tag, pd::tree_order_statistics_node_update>
//constexpr int N = 1E5 + 10, M = 1E9 + 7;
//constexpr ll INF = LLONG_MAX >> 1;
//constexpr double eps = 1E-9;

const int N = 1E5 + 10, M = 1E6 + 10;
const int D = 17;

using edge = tuple<int, int, int, int>;

int n, m;
vector<edge> e;
vector<pii> E[N];

int dep[N];
int p[D][N];
int val[D][N];

void DFS(int u, int pre){
    for (auto &x: E[u]){
        int v = x.st, w = x.nd;
        if (v == pre)
            continue;
        dep[v] = dep[u] + 1;
        p[0][v] = u;
        val[0][v] = w;
        DFS(v, u);
    }
}

void LCA_build(){
    for (int i = 1; i < D; ++i)
        for (int j = 1; j <= n; ++j){
            p[i][j] = p[i - 1][p[i - 1][j]];
            val[i][j] = max(val[i - 1][j], val[i - 1][p[i - 1][j]]);
        }
}

pii LCA_query(int u, int v){
    int rval = 0;
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = 0, t = dep[u] - dep[v]; t; ++i, t >>= 1)
        if (t & 1){
            rval = max(rval, val[i][u]);
            u = p[i][u];
        }
    if (u == v)
        return pii(u, rval);
    for (int i = D - 1; i >= 0; --i)
        if (p[i][u] != p[i][v]){
            rval = max(rval, max(val[i][u], val[i][v]));
            u = p[i][u];
            v = p[i][v];
        }
    rval = max(rval, max(val[0][u], val[0][v]));
    u = p[0][u];
    return pii(v, rval);
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e.emplace_back(w, u, v, i);
    }
    sort(all(e));

    vector<int> fa(n + 1,- 1);
    function<int(int)> find = [&](int x){return fa[x] < 0 ? x : (fa[x] = find(fa[x]));};
    for (auto &x: e){
        int u, v, w, i;
        tie(w, u, v, i) = x;
        int uu = find(u), vv = find(v);
        if (uu != vv){
            fa[uu] += fa[vv];
            fa[vv] = uu;

            E[u].emplace_back(v, w);
            E[v].emplace_back(u, w);

            x = edge(-1, -1, -1, -1);
        }
    }

    DFS(1, 0);
    LCA_build();
    vector<int> ans(m, -1);
    for (auto &x: e){
        int u, v, w, i;
        tie(w, u, v, i) = x;
        if (w < 0)
            continue;

        pii t = LCA_query(u, v);
        ans[i] = t.nd;
    }
    for (auto &x: ans)
        if (x >= 0)
            printf("%d\n", x);
    return 0;
}