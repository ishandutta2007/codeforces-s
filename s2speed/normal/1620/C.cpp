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

string s , ans;

void solve(){
	ans.clear();
	ll n , k , x , cur = 0;
	cin>>n>>k>>x>>s; x--;
	for(ll i = n - 1 ; i >= 0 ; i--){
		if(s[i] == '*'){
			cur++;
		} else {
			cur *= k; cur++;
			ll h = x % cur; x /= cur;
			while(h){
				ans += 'b';
				h--;
			}
			cur = 0;
			ans += 'a';
		}
	}
	cur *= k; cur++;
	ll h = x % cur; x /= cur;
	while(h){
		ans += 'b';
		h--;
	}
	cur = 0;
	reverse(all(ans));
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