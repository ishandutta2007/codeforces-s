// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=110;
const ll mod=1e9+7;

ll dg[maxn],f[maxn];
bool vis[maxn];

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    ll n;cin>>n;
    FOR(i,1,n){
	cin>>f[i];
	dg[f[i]]++;
    }
    FOR(i,1,n){
	if(dg[i]!=1){
	    cout<<-1;
	    return 0;
	}
    }
    ll ans=1;
    FOR(i,1,n){
	if(!vis[i]){
	    ll tmp=i,cnt=0;
	    while(!vis[tmp]){
		vis[tmp]=1;
		cnt++;
		tmp=f[tmp];
	    }
	    ans=(ans*cnt)/gcd(ans,cnt);
	}
    }
    if(ans%2==0)
	ans/=2;
    cout<<ans;
}