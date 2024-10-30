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

ll n;
ll a[maxn] , c[maxn];
vector<ll> v;
bitset<maxn> mark , dead;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>c[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		ll h = i , w = inf;
		while(true){
			if(dead[h]) break;
			if(mark[h]){
				while(v.back() != h){
					w = min(w , c[v.back()]);
					dead[v.back()] = true;
					v.pop_back();
				}
				w = min(w , c[h]);
				ans += w;
				break;
			}
			mark[h] = true;
			v.push_back(h);
			h = a[h];
		}
		while(!v.empty()){
			dead[v.back()] = true;
			v.pop_back();
		}
	}
	cout<<ans<<'\n';
	return 0;
}