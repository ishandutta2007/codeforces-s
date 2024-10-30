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
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef unordered_map<int,int> m32;
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
string s;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll n;
	cin >> n;
	ll a[n];
	forn(i,n) {cin >> a[i]; a[i]%=n;}
	v32 v;
	int t=0;
	rforn(i,n-1){
		int c = i - ((a[i]+t)%n) + n;
		c %= n;
		t += c;
		t %= n;
		v.pb(c);
	}
	cout << n+1 << ln;
	rforn(i,n-1){
		cout << 1 << " " << n-i << " " << v[i] << ln;
	}
	cout << 2 << " " << n << " " << n << ln;
}