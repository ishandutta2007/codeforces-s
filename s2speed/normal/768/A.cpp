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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

vector<ll> a;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , l = -1 , r;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		a.push_back(h);
	}
	sort(all(a));
	for(ll i = 1 ; i < n ; i++){
		if(a[i] != a[i - 1]){
			l = i;
			break;
		}
	}
	if(l == -1){
		cout<<"0\n";
		return 0;
	}
	for(ll i = n - 2 ; i >= 0 ; i--){
		if(a[i] != a[i + 1]){
			r = i;
			break;
		}
	}
	cout<<r - l + 1<<'\n';
	return 0;
}