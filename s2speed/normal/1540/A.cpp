#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

vector<ll> v;
ll ps[maxn];

void solve(){
	ll n , ans = 0;
	cin>>n;
	v.clear(); v.resize(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	sort(all(v));
	ps[0] = v[0];
	for(ll i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + v[i];
	}
	ans = v[n - 1];
	for(ll i = 1 ; i < n ; i++){
		ll h = -1ll * i * v[i] + ps[i - 1];
		ans += h;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}