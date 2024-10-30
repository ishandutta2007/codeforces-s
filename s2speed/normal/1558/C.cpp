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

const ll maxn = 3e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll p[maxn] , a[maxn];
vector<ll> ans , h;

void rev(ll x){
	h.clear();
	for(ll i = 0 ; i <= x ; i++){
		h.push_back(a[i]);
	}
	reverse(all(h));
	for(ll i = 0 ; i <= x ; i++){
		a[i] = h[i];
		p[a[i]] = i;
	}
	return;
}

void solve(){
	ans.clear();
	ll n;
	cin>>n;
	bool ch = false;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		p[a[i]] = i;
		ch |= (a[i] ^ i) & 1;
	}
	if(ch){
		cout<<"-1\n";
		return;
	}
	for(ll i = n - 1 ; i > 0 ; i -= 2){
		ans.push_back(p[i]);
		rev(p[i]);
		ans.push_back(p[i - 1] - 1);
		rev(p[i - 1] - 1);
		ans.push_back(p[i] + 2);
		rev(p[i] + 2);
		ans.push_back(2);
		rev(2);
		ans.push_back(i);
		rev(i);
	}
	cout<<sze(ans)<<'\n';
	for(auto i : ans){
		cout<<i + 1<<' ';
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