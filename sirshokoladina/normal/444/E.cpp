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

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define forv(i,v) for (auto i = v.begin(); i != v.end(); ++i)
#define forr(i,v) for (auto i = v.end(); i != v.begin() && (--i, 1); )
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 3000;

struct Input {
	int n;
	int a[N], b[N], c[N];
	int x[N];
	
	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n - 1) {
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			--a[i];
			--b[i];
		}
		forn (i, n) {
			scanf("%d", &x[i]);
		}
		return 1;
	}

	int ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int p[N], s[N], t[N];
	
	int P (int x) {
		if (p[x] == x) {
			return x;
		}
		return p[x] = P(p[x]);
	}
	
	void uni (int x, int y) {
		x = P(x);
		y = P(y);
		if (s[x] > s[y]) {
			swap(x, y);
		}
		p[x] = y;
		s[y] += s[x];
		t[y] += t[x];
	}
	
	void solve () {
		int m = accumulate(x, x + n, 0);
		forn (i, n) {
			p[i] = i;
			s[i] = 1;
			t[i] = x[i];
		}
		ve<pa<int, pii> > v;
		forn (i, n - 1) {
			v.pb(mp(c[i], mp(a[i], b[i])));
		}
		sort(all(v));
		forn (i, n - 1) {
			uni(v[i].sc.fs, v[i].sc.sc);
			int k = P(v[i].sc.fs);
			if (s[k] > m - t[k]) {
				ans = v[i].fs;
				return;
			}
		}
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
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
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