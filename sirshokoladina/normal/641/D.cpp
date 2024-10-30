#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	template<typename T> struct outputer;
	struct outputable {};
	#define PRINT(...)
	#define OUTPUT(...)
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
#define pb emplace_back
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

const int N = 100000;

struct Input {
	int n;
	double mx[N], mn[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%lf", &mx[i]);
		}
		forn (i, n) {
			scanf("%lf", &mn[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	
	double a[N], b[N];
	
	void write () {
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			printf("%lf", a[i]);
		}
		puts("");
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			printf("%lf", b[i]);
		}
		puts("");
	}
};

struct Solution: Data {
	ld sl[N + 1], sr[N + 1];
	ld ta[N + 1], tb[N + 1];
	
	void solve () {
		sl[0] = 0;
		forn (i, n) {
			sl[i + 1] = sl[i] + mx[i];
		}
		sr[n] = 0;
		ford (i, n) {
			sr[i] = sr[i + 1] + mn[i];
		}
		forn (i, n + 1) {
			ld A = 1;
			ld B = -(1 + sl[i] - sr[i]);
			ld C = sl[i];
			ld D = max<ld>(0, B * B - 4 * A * C);
			D = sqrtl(D);
			ta[i] = (-B - D) / (2 * A);
			tb[i] = (-B + D) / (2 * A);
		}
		forn (i, n) {
			a[i] = double(ta[i + 1] - ta[i]);
			b[i] = double(tb[i + 1] - tb[i]);
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