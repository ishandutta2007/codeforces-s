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

ll tv[8];

void solve(){
	ll a , t , b , r;
	cin>>a>>t>>b>>r;
	if(t > r){
		t = t - r;
		r = 0;
	} else {
		r = r - t;
		t = 0;
	}
	if(t > 6){
		cout<<">\n";
		return;
	}
	if(r > 6){
		cout<<"<\n";
		return;
	}
	a *= tv[t]; b *= tv[r];
	if(a > b){
		cout<<">\n";
		return;
	}
	if(a == b){
		cout<<"=\n";
		return;
	}
	cout<<"<\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	tv[0] = 1;
	for(ll i = 1 ; i <= 6 ; i++){
		tv[i] = tv[i - 1] * 10;
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}