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



signed main(){

    int t; cin >> t;
    REP(_, t){
        int n, a, b; cin >> n >> a >> b;
        if(a + b > n - 2 || llabs(a - b) > 1) cout << -1 << endl;
        else{
            vec p({0});
            if(a == b){
                FOR(k, 1, a + 1){
                    p.pb(k);
                    p.pb(-k);
                }
                int now = a + 1;
                while(SZ(p) < n){
                    p.pb(now);
                    now++;
                }
            }else if(a > b){
                FOR(k, 1, a + 1){
                    p.pb(k);
                    if(k < a) p.pb(-k);
                }
                int now = a;
                while(SZ(p) < n){
                    p.pb(-now);
                    now++;
                } 
            }else{
                FOR(k, 1, b + 1){
                    p.pb(-k);
                    if(k < b) p.pb(k);
                }
                int now = b;
                while(SZ(p) < n){
                    p.pb(now);
                    now++;
                } 
            }

            int m = 0;
            REP(i, n) chmin(m, p[i]);
            REP(i, n) p[i] -= m;
            REP(i, n) cout << p[i] + 1 << ' ';
            cout << endl;
        }
    }

    return 0;
}