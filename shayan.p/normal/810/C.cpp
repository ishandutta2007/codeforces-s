// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=3e5+10;
const ll mod=1e9+7;

ll a[maxn];

int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>a[i];
	sort(a,a+n);
	ll Min=0,ans=0,tw=1;
	REP(i,n){
		Min+=a[i];Min%=mod;
		ans+=(tw*a[i])-Min;ans%=mod;
		tw*=2;tw%=mod;
		Min=(Min-a[i])*2+a[i];Min%=mod;
	}
	cout<<(ans+mod)%mod;
}