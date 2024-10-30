#include <bits/stdc++.h>
#include <set>
#include <list>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef unordered_map<int,int> m32;
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
ll MOD = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int lim=1e5+5;
std::vector<std::vector<ll> > v(lim);
std::vector<ll> val(lim);
ll ans=0;
bool bo=false;

ll dfs(ll r, ll h, ll k){
	if(h%2==1){
		if(val[r]<k) bo=true;
		ans += val[r]-k;
		forn(i,(ll)v[r].size()){
			dfs(v[r][i],h+1,val[r]);
		}
		return val[r]-k;
	}
	else{
		ll m=1e9;
		forn(i,v[r].size()){
			m= min(m,dfs(v[r][i],h+1,k));
		}
		if((ll)v[r].size()) ans-=((ll)v[r].size()-1)*m;
		return 0;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll a;
    forn(i,n+1){
    	if(i==0 || i==1) continue;
    	cin >> a;
    	v[a].pb(i);
    }
    forn(i,n+1){
    	if(i==0) continue;
    	cin >> val[i];
    }
    dfs(1,1,0);
    if(bo) cout << -1;
    else cout << ans;
    return 0;
}