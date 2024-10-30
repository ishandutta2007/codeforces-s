#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e5 + 15 , md = 1e9 + 7 , inf = 2e9;

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

ll cnt[MAXN] , a[MAXN];

void solve(){
	ll n , m , h , ans;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i] %= m;
		cnt[a[i]]++;
	}
	ans = (cnt[0] > 0);
	if(m % 2 == 0){
		ans += (cnt[m / 2] > 0);
	}
	ll lm = (m + 1) / 2;
	for(ll i = 1 ; i < lm ; i++){
		ll j = m - i , d;
		if(cnt[i] > 0 || cnt[j] > 0) ans++;
		d = max(0ll , abs(cnt[i] - cnt[j]) - 1);
		ans += d;
	}
	for(ll i = 0 ; i < n ; i++){
		cnt[a[i]]--;
	}
	cout<<ans<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/