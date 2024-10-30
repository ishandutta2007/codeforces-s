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
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define pb push_back
#define fi first
#define se second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); i++) { cout << v[i]; if(i != v.size() - 1) cout << endl; }; return os; }
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

const int mod = 1000000007;
//const int mod = 998244353;

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

        //if(sz[x] < sz[y]) swap(x, y);

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



signed main(){

    int n, m, x; cin >> n >> m >> x;
    vec a(n); cin >> a;
    int S = 0;
    REP(i, n) S += a[i];
    if(S < (n - 1) * x){
        Out("NO");
        return 0;
    }

    vec u(m), v(m);
    vector<set<int>> es(n);
    set<int> rest;
    UnionFind UF0(n);
    REP(i, m){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        if(!UF0.is_union(u[i], v[i])){
            UF0.unite(u[i], v[i]);
            rest.insert(i);
            es[u[i]].insert(i);
            es[v[i]].insert(i);
        }
    }

    set<Pii> ai;
    vec ans;
    REP(i, n) ai.insert(Pii(a[i], i));
    UnionFind UF(n);
    while(UF.n_cc > 1){
        auto it = ai.end(); it--;
        int i;
        if((*it).fi >= x){
            int v = (*it).se;
            i = *(es[v].begin());
        }else{
            i = *(rest.begin());
        }
        ans.pb(i);
        int xx = UF.find(u[i]), yy = UF.find(v[i]);
        ai.erase(Pii(a[xx], xx)); ai.erase(Pii(a[yy], yy));
        es[xx].erase(i); es[yy].erase(i);

        if(SZ(es[xx]) < SZ(es[yy])) swap(xx, yy);
        for(int j: es[yy]) es[xx].insert(j);
        es[yy].erase(all(es[yy]));
        UF.unite(xx, yy);
        a[xx] = a[xx] + a[yy] - x;
        ai.insert(Pii(a[xx], xx));
        rest.erase(i);
    }
    Out("YES");
    REP(i, n - 1) cout << ans[i] + 1 << '\n';

    return 0;
}