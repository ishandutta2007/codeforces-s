#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll a[maxn];

void solve(){
	ll n;
	bool f = true;
	ll c = inf , m = -1;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		f &= (a[i] >= h);
		if(h > 0){
			if(c == inf){
				c = a[i] - h;
			} else {
				if(c != a[i] - h){
					f = false;
				}
			}
		} else {
			m = max(m , a[i]);
		}
	}
	f &= (m <= c);
	cout<<(f ? "YES\n" : "NO\n");
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}