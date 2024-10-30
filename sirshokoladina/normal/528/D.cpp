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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const double pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 200000;
const int C = 4;
const char c[C + 1] = "ATGC";

struct Input {
	int n, m, k;
	string s, t;
	
	bool read () {
		if (!(cin >> n >> m >> k)) {
			return 0;
		}
		getline(cin, s);
		getline(cin, s);
		getline(cin, t);
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
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
	
	static const int L = 18;
	static const int M = 1 << L;
	
	void butterfly (double *x, double *y, int n) {
		int j = 0;
		forn (i, 1, n) {
			int k = n >> 1;
			while (j >= k) {
				j -= k;
				k >>= 1;
			}
			j += k;
			if (i < j) {
				swap(x[i], x[j]);
				swap(y[i], y[j]);
			}
		}
	}
	
	void fft (double *x, double *y, int n) {
		butterfly(x, y, n);
		for (int m = 1; m < n; m <<= 1) {
			double rx = cos(pi / m), ry = sin(pi / m);
			for (int k = 0; k < n; k += m << 1) {
				double wx = 1, wy = 0;
				for (int j = k; j < k + m; j++) {
					double ux = x[j], uy = y[j];
					double vx = x[j + m] * wx - y[j + m] * wy;
					double vy = x[j + m] * wy + y[j + m] * wx;
					x[j] = ux + vx;
					y[j] = uy + vy;
					x[j + m] = ux - vx;
					y[j + m] = uy - vy;
					double x_ = wx;
					wx = x_ * rx - wy * ry;
					wy = x_ * ry + wy * rx;
				}
			}
		}
	}
	
	void inv (double *x, double *y, int n) {
		forn (i, n) {
			x[i] /= n;
			y[i] /= n;
		}
		reverse(x + 1, x + n);
		reverse(y + 1, y + n);
	}
	
	double ax[M], ay[M], dx[M], dy[M];
	
	void solve () {
		int sz = 1;
		while (sz < max(n, m)) {
			sz *= 2;
		}
		
		memset(dx, 0, sizeof dx);
		memset(dy, 0, sizeof dy);
		forn (w, C) {
			memset(ax, 0, sizeof ax);
			memset(ay, 0, sizeof ay);
			forn (i, n) {
				ax[i] = (s[i] == c[w]);
			}
			forn (i, m) {
				ay[m - 1 - i] = (t[i] == c[w]);
			}
			{
				int lst = -N - 10;
				forn (i, n) {
					if (ax[i] > 0.5) {
						lst = i;
					}
					if (abs(i - lst) <= k) {
						ax[i] = 1;
					}
				}
			}
			{
				int lst = 2 * N + 10;
				ford (i, n) {
					if (ax[i] > 0.5) {
						lst = i;
					}
					if (abs(i - lst) <= k) {
						ax[i] = 1;
					}
				}
			}
			
			forn (i, sz) {
				ax[i] = (ax[i] + ay[i]) / 2;
				ay[i] -= ax[i];
			}
			fft(ax, ay, sz);
			forn (i, sz) {
				dx[i] += ax[i] * ax[i] - ay[i] * ay[i];
				dy[i] += 2 * ax[i] * ay[i];
			}
		}
		
		fft(dx, dy, sz);
		inv(dx, dy, sz);
		
		ans = 0;
		forn (i, n - m + 1) {
			ans += int(dx[i + m - 1] + 0.5) == m;
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