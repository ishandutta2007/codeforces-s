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
const ll mod=1e9+7;
const ll maxn=1e5+10;

ll a[maxn],Max[maxn],Min[maxn];

int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>a[i];
	ll ans=-inf;
	FORD(i,n-2,0){
		Max[i]=abs(a[i+1]-a[i])-min(ll(0),Min[i+1]);
		Min[i]=abs(a[i+1]-a[i])-max(ll(0),Max[i+1]);
		ans=max(ans,Max[i]);
	}
	cout<<ans;
}