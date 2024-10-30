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

const ll maxn = 500 + 16 , md = 1e9 + 7 , inf = 2e16;

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

char a[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		for(ll j = 0 ; j < n ; j++){
			a[i][j] = s[j];
		}
	}
	ll ans = 0;
	for(ll i = 1 ; i < n - 1 ; i++){
		for(ll j = 1 ; j < n - 1 ; j++){
			ll cnt = 0;
			if(a[i][j] == 'X') cnt++;
			if(a[i + 1][j + 1] == 'X') cnt++;
			if(a[i + 1][j - 1] == 'X') cnt++;
			if(a[i - 1][j + 1] == 'X') cnt++;
			if(a[i - 1][j - 1] == 'X') cnt++;
			if(cnt == 5) ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}