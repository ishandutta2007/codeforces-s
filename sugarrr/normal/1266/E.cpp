#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////




int main(){fastio
    ll n;cin>>n;
    ll a[n+1];rep(i,1,n)cin>>a[i];
    ll ans=0;rep(i,1,n)ans+=a[i];
    ll q;cin>>q;
    ll count[n+1];memset(count,0,sizeof(count));
    set<l_l>se[n+1];
    while(q--){
        ll s,t,u;cin>>s>>t>>u;
        l_l p=*lower_bound(se[s].begin(),se[s].end(),l_l(t,0));
        if(p.first==t){
            se[s].erase(p);
            if(count[p.second]<=a[p.second])ans++;
            count[p.second]--;
            if(u!=0){
                se[s].insert(l_l(t,u));
                if(count[u]<a[u])ans--;
                count[u]++;
            }
        }else{
            if(u!=0){
                se[s].insert(l_l(t,u));
                if(count[u]<a[u])ans--;
                count[u]++;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}