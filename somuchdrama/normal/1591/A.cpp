#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sz(a)((int)(a).size())
#define sqr(x) ((x)*(x))
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
#else
#define dbg(...) 
#endif
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};

int32_t main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x=1;
        vector<int> a(n);
        forn(i,n){
            cin>>a[i];
        }
        forn(i,n){
            if(i>0&&!a[i]&&!a[i-1]){
                x=-1;
                break;
            }
            else if(i>0&&a[i]&&a[i-1]){
                x+=5;
            }else if(a[i]){
                x++;
            }
        }
        cout<<x<<'\n';
    }    

    return 0;
}