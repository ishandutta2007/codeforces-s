#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
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

const int N=1e6+6;
int a[N];
int ans=1e18;
int n;
int s=0;
vector<int> pos;
void check(int x){
    int cur=0;
    int l=0,r=x;
    int m=(l+r)/2;
    forn(i,s/x){
        for(int j=l;j<r;++j){
            if(j<m)cur+=pos[m]-pos[j];
            else cur+=pos[j]-pos[m];
        }
        l+=x;
        r+=x;
        m+=x;
    }
    upn(ans,cur);
}
int32_t main(){
    cin>>n;
    forn(i,n){
        cin>>a[i];
        s+=a[i];
        if(a[i]){
            pos.pb(i);
        }
    }
    if(s==1){
        cout<<"-1\n";
        return 0;
    }
    for(int x=2;x*x<=s;++x){
        if(s%x==0){
            check(x);
            if(x*x!=s)check(s/x);
        }
    }
    check(s);
    cout<<ans<<'\n';
    return 0;
}