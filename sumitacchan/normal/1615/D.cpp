#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, (int)v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, (int)m.size()){ REP(j_debug, (int)m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define pb push_back
#define fi first
#define se second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < (int)v.size(); i++) { cout << v[i]; if(i != (int)v.size() - 1) cout << endl; }; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p){ cout << '(' << p.first << ',' << p.second << ')'; return os; }
template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void chOut(bool f, T1 y, T2 n) { if(f) Out(y); else Out(n); }

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using v_bool = vector<bool>;
using v_Pii = vector<Pii>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

//const int mod = 1000000007;
const int mod = 998244353;

struct UnionFind
{
    vector<int> par, sz;
    int n_cc;

    UnionFind(int N){
        par = vector<int>(N);
        REP(i, N) par[i] = i;
        sz = vector<int>(N, 1);
        n_cc = N;
    }

    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;

        if(sz[x] < sz[y]) swap(x, y);

        par[y] = x;
        sz[x] += sz[y];
        n_cc--;
    }

    bool is_union(int x, int y){
        x = find(x);
        y = find(y);
        return x == y;
    }

    int union_size(int x){
        return sz[find(x)];
    }

};


struct edge{int to, cost, id;};

class Graph
{
public:
    int N;
    vector<vector<edge>> G;
    vec ans;

    Graph(int N): N(N){
        G = vector<vector<edge>>(N, vector<edge>(0));
        ans = vec(N - 1);
    }

    void add_Directed_edge(int from, int to, int cost = 1, int id = 0){
        G[from].push_back(edge({to, cost, id}));
    }

    void add_Undirected_edge(int v1, int v2, int cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

};

signed main(){

    int t; cin >> t;
    REP(_, t){
        int n, m; cin >> n >> m;
        //Graph G(n);
        vec x(n - 1), y(n - 1), v(n - 1);
        REP(i, n - 1){
            cin >> x[i] >> y[i] >> v[i];
            x[i]--; y[i]--;
            //int cost = (v[i] == -1 ? __builtin_popcountll(v[i]) % 2);
            //G.add_Undirected_edge(x[i], y[i], cost, i);
        }

        UnionFind UF(2 * n);
        REP(i, m){
            int a, b, p; cin >> a >> b >> p;
            a--; b--;
            if(p == 0){
                UF.unite(a, b);
                UF.unite(a + n, b + n);
            }else{
                UF.unite(a, b + n);
                UF.unite(a + n, b);
            }
        }
        REP(i, n - 1) if(v[i] != -1){
            if(__builtin_popcountll(v[i]) % 2 == 0){
                UF.unite(x[i], y[i]);
                UF.unite(x[i] + n, y[i] + n);
            }else{
                UF.unite(x[i], y[i] + n);
                UF.unite(x[i] + n, y[i]);
            }
        }

        bool ok = true;
        REP(i, n) if(UF.is_union(i, i + n)) ok = false;
        if(ok){
            cout << "YES\n";
            REP(i, n - 1){
                int cost;
                if(v[i] != -1) cost = v[i];
                else if(UF.is_union(x[i], y[i])) cost = 0;
                else if(UF.is_union(x[i], y[i] + n)) cost = 1;
                else{
                    cost = 0;
                    UF.unite(x[i], y[i]);
                    UF.unite(x[i] + n, y[i] + n);
                }
                cout << x[i] + 1 << ' ' << y[i] + 1 << ' ' << cost << '\n';
            }
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}