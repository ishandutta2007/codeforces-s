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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll a[maxn];

int main(){
	ll n,u;cin>>n>>u;
	REP(i,n)
		cin>>a[i];
	ld ans=-1;
	ll r=1;// ta ghabl az in okey e
	REP(l,n){
		while(r<n&&(a[r]-a[l])<=u)
			r++;
		if((r-1-l)<2)
			continue;
		ans=max(ans,(ld(a[r-1]-a[l+1])/ld(a[r-1]-a[l])));
	}
	if(ans==-1)
		cout<<-1;
	else
		cout<<setprecision(12)<<fixed<<ans;
}