#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>

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
ll MOD = 998244353;
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
#define INF LLONG_MAX

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll a[n],b[n],d[n];
    set<p64> s;
    forn(i,n){
    	cin >> a[i];
    	s.insert(mp(-1*a[i]*(i+1)*(n-i),i));
    }
    forn(i,n){
    	cin >> b[i];
    	d[i]=b[i];
    }
    sort(d,d+n);
    ll in=0;
    for(auto it:s){
    	b[it.se]=d[in++];
    }
    ll ans=0;
    forn(i,n){
    	ans += (((a[i]*b[i])%MOD) *(((i+1)*(n-i))%MOD))%MOD;
    	ans %= MOD;
    }
    cout << ans << ln;
    return 0;
}