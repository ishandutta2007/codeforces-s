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
const ll maxn=2e5+10;

int main(){
	ll n;cin>>n;
	ll ans=0;
	REP(i,n){
		string s;cin>>s;
		if(s=="Tetrahedron")ans+=4;
		if(s=="Cube")ans+=6;
		if(s=="Octahedron")ans+=8;
		if(s=="Dodecahedron")ans+=12;
		if(s=="Icosahedron")ans+=20;
	}
	cout<<ans;
}