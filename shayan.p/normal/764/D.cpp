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

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;

#pragma GCC Optimize("Ofast")

ll ans[maxn];

int main(){
	ll n;cin>>n;
	REP(i,n){
		ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
		ll mx=min(x1,x2);
		ll my=min(y1,y2);
		mx%=2;
		my%=2;
		mx+=2;
		my+=2;
		ans[i]=2*(mx%2)+(my%2);
	}
	cout<<"YES\n";
	REP(i,n)
		cout<<ans[i]+1<<endl;
	
}