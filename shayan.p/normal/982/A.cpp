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
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

vector<ll>v;

int main(){
	ll n;cin>>n;
	v.PB(0);
	REP(i,n){
		char x;cin>>x;
		v.PB((x=='1'));
	}
	v.PB(0);
	FOR(i,1,sz(v)-1){
		if(v[i]==1&&v[i-1]==1){
			cout<<"No";
			return 0;
		}
	}
	FOR(i,2,sz(v)-1){
		if(v[i]==0&&v[i-1]==0&&v[i-2]==0){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
}