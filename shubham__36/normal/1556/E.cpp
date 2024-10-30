#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
// #include <atcoder/all>
// #include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
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
#include <iomanip>
#include <fstream>

using namespace std;
// using namespace atcoder;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<p64, p64> pp64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef pair<ll, p64> tp;
ll MOD = 1e9+7;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln '\n'
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define zero ll(0)
#define set_bits(x) __builtin_popcountll(x)
// #define mint modint998244353

ll mpow(ll a, ll b)
{
	if (a == 0)
		return 0;
	if (b == 0)
		return 1;
	ll t1 = mpow(a, b / 2);
	t1 *= t1;
	t1 %= MOD;
	if (b % 2)
		t1 *= a;
	t1 %= MOD;
	return t1;
}

ll mpow(ll a, ll b, ll p)
{
	if (a == 0)
		return 0;
	if (b == 0)
		return 1;
	ll t1 = mpow(a, b / 2, p);
	t1 *= t1;
	t1 %= p;
	if (b % 2)
		t1 *= a;
	t1 %= p;
	return t1;
}

ll modinverse(ll a, ll m)
{
	ll m0 = m;
	ll y = 0, x = 1;
	if (m == 1)
		return 0;
	while (a > 1)
	{
		ll q = a / m;
		ll t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0)
		x += m0;
	return x;
}

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

ll range(ll l, ll r)
{
	return l + mt() % (r - l + 1);
}

ll rev(ll v)
{
	return mpow(v, MOD - 2);
}

ll nc2(ll n)
{
	return (n * (n - 1)) / 2;
}

class SegmentTreemin {
	ll n;
	v64 t;

	public:

	SegmentTreemin(const v64 &a){
		n = (ll)a.size();
		t.assign(2*n,0);
		forn(i,n) t[n+i]=a[i];
		build();
	}

	void build() {  // build the tree
	  rforn(i,n-1) t[i] = min(t[i<<1],t[i<<1|1]);
	}

	ll query(ll l, ll r) {  // sum on interval [l, r)
	  ll res = INF;
	  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	    if (l&1) res = min(res,t[l++]);
	    if (r&1) res = min(res,t[--r]);
	  }
	  return res;
	}
};

class SegmentTreemax {
	ll n;
	v64 t;

	public:

	SegmentTreemax(const v64 &a){
		n = (ll)a.size();
		t.assign(2*n,0);
		forn(i,n) t[n+i]=a[i];
		build();
	}

	void build() {  // build the tree
	  rforn(i,n-1) t[i] = max(t[i<<1],t[i<<1|1]);
	}

	ll query(ll l, ll r) {  // sum on interval [l, r)
	  ll res = -INF;
	  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	    if (l&1) res = max(res,t[l++]);
	    if (r&1) res = max(res,t[--r]);
	  }
	  return res;
	}
};

void solve()
{
	ll n,k;
	cin >> n >> k;
	ll a[n];
	forn(i,n){
		cin >> a[i];
	}
	v64 ps(1,0);
	forn(i,n){
		ll tmp;
		cin >> tmp;
		a[i] -= tmp;
		ps.pb(ps.back()+a[i]);
	}
	SegmentTreemax S1(ps);
	SegmentTreemin S2(ps);
	// cout << ln;
	forn(i,k){
		ll l,r;
		cin >> l >> r;
		l--;
		ll mmin = S2.query(l,r);
		ll mmax = S1.query(l,r);
		if(ps[l]==ps[r] && ps[l]==mmax){
			cout << mmax-mmin << ln;
		}
		else cout << -1 << ln;
	}
}

int main()
{
	fast_cin();
	ll t = 1;
	// cin >> t;
	forn(i, t)
	{
		// cout << "Case #" << i+1 << ": ";
		solve();
	}
	return 0;
}