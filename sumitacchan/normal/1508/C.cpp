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


signed main(){

    int n, m; cin >> n >> m;
    vec u(m), v(m), w(m);
    vector<set<int>> connected(n);
    int W = 0;
    REP(i, m){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--; v[i]--;
        connected[u[i]].insert(v[i]);
        connected[v[i]].insert(u[i]);
        W ^= w[i];
    }

    set<int> rest;
    REP(i, n) rest.insert(i);
    UnionFind UF(n);
    int n0 = 0;
    REP(i, n) if(rest.count(i)){
        queue<int> que;
        que.push(i);
        rest.erase(i);
        while(!que.empty()){
            int x = que.front(); que.pop();
            set<int> tmp;
            tmp.swap(rest);
            for(int y: connected[x]) if(tmp.count(y)){
                rest.insert(y);
                tmp.erase(y);
            }
            for(int y: tmp){
                UF.unite(x, y);
                n0++;
                que.push(y);
            }
        }
    }

    int ans = INF, tot = 0;
    v_Pii p(m);
    REP(i, m) p[i] = Pii(w[i], i);
    Sort(p);
    UnionFind UF2(n);
    REP(i0, m){
        int i = p[i0].se;
        if(!UF.is_union(u[i], v[i])){
            tot += w[i];
            UF.unite(u[i], v[i]);
            UF2.unite(u[i], v[i]);
        }
    }
    
    if(n0 == n * (n - 1) / 2 - m){
        ans = tot + W;
        REP(i0, m){
            int i = p[i0].se;
            if(!UF2.is_union(u[i], v[i])){
                chmin(ans, tot + w[i]);
            }
        }
    }else{
        ans = tot;
    }
    Out(ans);

    return 0;
}