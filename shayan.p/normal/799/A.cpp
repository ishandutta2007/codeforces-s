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
const ll mod=1e9+7;
const ll maxn=2e5+10;

#pragma GCC Optimize("Ofast")

int main(){
	ll n,t,k,d;cin>>n>>t>>k>>d;
	ll t1=t*((n/k)+(n%k!=0));
	ll T=t1-1;
	ll cake=(k*(T/t))+((T-d<0)?0:(k*((T-d)/t)));
	if(cake>=n)
		cout<<"YES";
	else
		cout<<"NO";
}