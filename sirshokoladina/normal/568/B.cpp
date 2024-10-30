#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t ui;
typedef uint16_t us;
typedef uint8_t uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const ll mod = 1000000007;
const int N = 4000;

struct Input {
	int n;
	
	bool read () {
		return cin >> n;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	ll f[N + 1];
	ll rf[N + 1];
	
	ll pw (ll a, ll n) {
		ll ans = 1;
		while (n) {
			if (n & 1) {
				ans = ans * a % mod;
			}
			a = a * a % mod;
			n >>= 1;
		}
		return ans;
	}
	
	ll C (int n, int k) {
		return f[n] * rf[k] % mod * rf[n - k] % mod;
	}
	
	ll a[N + 1], b[N + 1];
	
	void solve () {
		f[0] = 1;
		forn (i, N) {
			f[i + 1] = f[i] * (i + 1) % mod;
		}
		forn (i, N + 1) {
			rf[i] = pw(f[i], mod - 2);
		}
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		a[0] = 1;
		b[0] = 1;
		forn (i, 1, N + 1) {
			forn (j, i) {
				a[i] = (a[i] + C(i - 1, j) * a[j]) % mod;
			}
			forn (j, i - 1) {
				b[i] = (b[i] + C(i - 1, j) * b[j]) % mod;
			}
			b[i] = (b[i] + 2 * b[i - 1]) % mod;
		}
		debug(a, a + 10);
		debug(b, b + 10);
		ans = (b[n] - a[n] + mod) % mod;
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	freopen((problemname + ".in").c_str(), "r", stdin);
//	freopen((problemname + ".out").c_str(), "w", stdout);
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}