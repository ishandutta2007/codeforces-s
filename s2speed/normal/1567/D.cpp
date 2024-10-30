#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll cnt[12];
vector<ll> v;

void solve(){
	memset(cnt , 0 , sizeof(cnt));
	v.clear();
	ll s , n;
	cin>>s>>n;
	ll h = s , o = 0;
	for(ll i = 0 ; h ; i++){
		cnt[i] += h % 10;
		h /= 10;
		o += cnt[i];
	}
	while(o < n){
		for(ll i = 1 ; i < 12 ; i++){
			if(cnt[i] > 0){
				cnt[i]--;
				cnt[i - 1] += 10;
				o += 9;
				break;
			}
		}
	}
	for(ll i = 1 ; i < n ; i++){
		ll h = 0 , cur = 1;
		for(ll j = 0 ; j < 12 ; j++){
			if(cnt[j]){
				h = cur;
				cnt[j]--;
				break;
			}
			cur *= 10;
		}
		v.push_back(h);
	}
	ll cur = 1;
	h = 0;
	for(ll j = 0 ; j < 12 ; j++){
		ll o = 1ll * cur * cnt[j];
		h += o;
		cur *= 10;
	}
	v.push_back(h);
	for(auto i : v){
		cout<<i<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}