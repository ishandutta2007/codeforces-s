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

const int mod = 1000000007;
//const int mod = 998244353;



signed main(){

    int t; cin >> t;
    REP(_, t){
        int n, m; cin >> n >> m;
        vec a(n); cin >> a;
        a.pb(-1.0e12); a.pb(1.0e12);
        Sort(a);
        
        vector<v_Pii> lr(n + 1);
        REP(i, m){
            int l, r; cin >> l >> r;
            int i0 = Upper_bound(a, r);
            if(a[i0 - 1] < l) lr[i0 - 1].pb(Pii(l, r));
        }
        REP(i, n + 1) Sort(lr[i]);

        //vdebug(a); mdebug(lr);

        mat dp(n + 2, vec(2, INF));
        dp[0][0] = 0;
        FOR(i, 1, n + 2){
            //(a[i-1],a[i])
            int sz = SZ(lr[i - 1]);
            int rmin = a[i];
            v_Pii p(sz + 1);
            IREP(k, sz){
                p[k + 1] = Pii(lr[i - 1][k].fi, rmin);
                chmin(rmin, lr[i - 1][k].se);
            }
            p[0] = Pii(a[i - 1], rmin);

            REP(k, sz + 1){
                int cl = p[k].fi - a[i - 1], cr = a[i] - p[k].se;
                chmin(dp[i][0], min(dp[i - 1][0] + cl + 2 * cr, dp[i - 1][1] + 2 * cl + 2 * cr));
                chmin(dp[i][1], min(dp[i - 1][0] + cl + cr, dp[i - 1][1] + 2 * cl + cr));
            }
        }
        int ans = min(dp[n + 1][0], dp[n + 1][1]);
        Out(ans);
    }

    return 0;
}