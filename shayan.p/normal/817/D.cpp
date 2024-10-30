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
const ll maxn=1e6+10;

struct Number{
	ll big,val,where;
};
deque<Number>d;
ll ans=0;
ll a[maxn];

int main(){
	ll n;cin>>n;
	REP(i,n){
		cin>>a[i];
	}
	d.clear();
	REP(i,n){
		while(sz(d)&&d.back().big<=a[i]){
			d.POB();
		}
		ll Val;
		if(sz(d)==0){
			Val=(i+1)*a[i];
		}
		else{
			Val=d.back().val+((i-d.back().where)*a[i]);
		}
		ans+=Val;
		Number Num;
		Num.where=i;
		Num.big=a[i];
		Num.val=Val;
		d.PB(Num);
	}
	d.clear();
	REP(i,n){
		while(sz(d)&&d.back().big>=a[i]){
			d.POB();
		}
		ll Val;
		if(sz(d)==0){
			Val=(i+1)*a[i];
		}
		else{
			Val=d.back().val+((i-d.back().where)*a[i]);
		}
		ans-=Val;
		Number Num;
		Num.where=i;
		Num.big=a[i];
		Num.val=Val;
		d.PB(Num);
	}
	cout<<ans;
}