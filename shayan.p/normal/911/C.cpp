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
const ll maxn=2e5+10;

int main(){
	ll a[3];cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if((a[0]==1)||(a[0]==2&&a[1]==2)||(a[0]==3&&a[2]==3)||(a[0]==2&&a[1]==4&&a[2]==4))
		cout<<"YES";
	else
		cout<<"NO";
}