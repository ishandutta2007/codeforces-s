#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#endif
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<long double,long double>pdd;
typedef vector<int>vi;
typedef vector<ll>vl;
typedef long  double ld;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=5000+10,M=500;
const ll mod=1e9+7;

void solve(){
    int x,y;cin>>x>>y;
    if((x+y)%2){
        cout<<"-1 -1";
        return;
    }
    cout<<x/2<<' '<<(y+1)/2;
}
int main(){
    freopen("A.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    int _;cin>>_;
    while(_--){
        solve();
        cout<<endl;
    }
}