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
	#define fbegin(...)
	#define fend
	#define pbegin(...)
	#define pend
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

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 200000;
const int M = 100000;

struct Input {
	string s;
	int m;
	int l1[M], r1[M], l2[M], r2[M];
	
	bool read () {
		string s1, s2;
		if (!getline(cin, s1) || !getline(cin, s2)) {
			return 0;
		}
		s = s1 + s2;
		cin >> m;
		forn (i, m) {
			scanf("%d%d%d%d", &l1[i], &r1[i], &l2[i], &r2[i]);
			--l1[i];
			--l2[i];
			l2[i] += sz(s1);
			r2[i] += sz(s1);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans[M];
	
	void write () {
		forn (i, m) {
			printf("%d", int(ans[i]));
		}
		puts("");
	}
};


namespace Main {
	
	struct Solution: Data {
		int cnta[N + 1], cntb[N + 1];
		
		void solve () {
			cnta[0] = 0;
			cntb[0] = 0;
			forn (i, sz(s)) {
				if (s[i] == 'A') {
					cnta[i + 1] = cnta[i] + 1;
					cntb[i + 1] = cntb[i];
				} else {
					cnta[i + 1] = 0;
					cntb[i + 1] = cntb[i] + 1;
				}
			}
			debug(s);
			debug(cnta, cnta + sz(s) + 1);
			debug(cntb, cntb + sz(s) + 1);
			forn (i, m) {
				debug(mt(s.substr(l1[i], r1[i] - l1[i]), s.substr(l2[i], r2[i] - l2[i])));
				int a1 = min(cnta[r1[i]], r1[i] - l1[i]);
				int b1 = cntb[r1[i]] - cntb[l1[i]];
				int a2 = min(cnta[r2[i]], r2[i] - l2[i]);
				int b2 = cntb[r2[i]] - cntb[l2[i]];
				debug(mt(a1, b1, a2, b2));
				if (b1 == b2) {
					ans[i] = (a1 >= a2 && (a1 - a2) % 3 == 0);
				} else {
					if (b1 == 0) {
						ans[i] = (b2 % 2 == 0 && a1 > a2);
					} else {
						ans[i] = (b2 >= b1 && (b2 - b1) % 2 == 0 && a1 >= a2);
					}
				}
			}
		}
		
		void clear () {
			*this = Solution();
		}
	};
}


Main::Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);

	#ifdef SG
		freopen((problemname + ".in").c_str(), "r", stdin);
//		freopen((problemname + ".out").c_str(), "w", stdout);
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
	
	/*
	int t;
	cin >> t;
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	*/
	
	return 0;
}