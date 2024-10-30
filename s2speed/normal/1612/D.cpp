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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
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

ll k , x;

bool check(ll m){
	ll h = 0;
	if(m <= k){
		return (1ll * m * (m + 1) / 2 < x);
	}
	h = 1ll * k * k;
	ll g = 2 * k - m - 1;
	h -= 1ll * g * (g + 1) / 2;
	return (h < x);
}

void solve(){
	ll a , b , x;
	cin>>a>>b>>x;
	if(a < b) swap(a , b);
	while(b > 0 && x <= a){
		if(x % b == a % b){
			cout<<"YES\n";
			return;
		}
		a = a % b; swap(a , b);
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}