#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
// #define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}

const int N=81,K=11,OO=1e9+7;
int a[N][N];
int p[N];
int dp[K][N];

int32_t main(){
    int n,k;
    cin>>n>>k;
    forn(i,n){
        forn(j,n){
            cin>>a[i][j];
        }
    }
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    int ans=OO;
    while(1.0*clock()/CLOCKS_PER_SEC<2.85){
        forn(i,n)p[i]=rng()&1;
        forn(i,k+1)forn(v,n)dp[i][v]=OO;
        dp[0][0]=0;
        forn(i,k){
            forn(v,n){
                if(dp[i][v]==OO)continue;
                forn(to,n){
                    if(p[to]==p[v])continue;
                    upn(dp[i+1][to],dp[i][v]+a[v][to]);
                }
            }
        }
        upn(ans,dp[k][0]);
    }
    cout<<ans<<'\n';

    return 0;
}