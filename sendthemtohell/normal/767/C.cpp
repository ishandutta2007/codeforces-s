#pragma GCC optimize("O3")

#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <locale>
#include <numeric>
#include <regex>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define speedup cout.tie(nullptr);cin.tie(nullptr);ios_base::sync_with_stdio(false);
#define coutdouble cout<<setprecision(20);cout<<fixed;
/*------CommentInInteractive--------*/
#define endl "\n"
/*----------------------------------*/
const int INF = 1000 * 1000 * 1000;
const ll LLINF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
const int MOD = 1000 * 1000 * 1000 + 7;
const int RMOD = MOD - 2;
const int N = 1000*1000 + 322;
const int P1M = 1336337; //Large prime number ( ~1M )
const int P1K = 1009; //Big prime ( ~1K )
const ld Pi = acos(-1);
/*--------------------------------------------------IO_FILES-----------------------------------------------*/
const char * infile =
#ifdef LOCAL
"input.txt"
#else
""
#endif
;
const char * outfile =
#ifdef LOCAL
""
#else
""
#endif
;
/*----------------------------------------------------MATHS------------------------------------------------*/
inline int gcd(int a, int b) { while (b) { int tmp = a%b; a = b; b = tmp; } return a; }
inline void gcd(vector<int> a) { while (a.size() > 1) { int tmp1 = a.back(), tmp2 = a.back(); a.pop_back(), a.pop_back(); a.push_back(gcd(tmp1, tmp2)); } }
inline ll pwm(ll x, ll pow) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= x; x *= x; pow >>= 1; x %= MOD; mlt %= MOD; } else { pow >>= 1; x *= x; x %= MOD; } }return mlt; }
inline ll pw(ll x, int pow) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= x; x *= x; pow >>= 1; } else { pow >>= 1; x *= x; } }return mlt; }
inline ll rev(ll r) { return pwm(r, RMOD); }
/*--------------------------------------------------------------------------------------------------------*/

vector<int> g[N];
int wt[N];
bool used[N];
int ans1, ans2, acc, bgin = -1;

int dfs(int v) {
	int cv = wt[v];
	used[v] = true;
	for (auto &u : g[v]) {
		if (!used[u])
			cv += dfs(u);
	}
	if (cv == acc && v != bgin) {
		if (ans1) {
			ans2 = v+1;
			cout << ans1 << " " << ans2 << endl;
//			while (true);
			exit(0);
		}
		else 
		{
			ans1 = v+1;
			cv = 0;
		}
	}
	return cv;
}

inline void solve(ld tt) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int j, val;
		cin >> j >> val;
		acc += val;
		if (j) {
			g[j - 1].pb(i);
			g[i].pb(j - 1);
		}
		else {
			assert(bgin == -1);
			bgin = i;
		}
		wt[i] = val;
	}
	if (acc % 3) {
		cout << -1 << endl;
		return;
	}
	acc /= 3;
	dfs(bgin);
	cout << -1 << endl;
}

int main() {
	ld tt = clock();
	freopen(infile, "r", stdin);
	freopen(outfile, "w", stdout);

	speedup
	coutdouble

	solve(tt);

#ifdef LOCAL
	cout << "Time: " << ((ld)clock() - tt) / CLOCKS_PER_SEC << endl;
	while (true);
#endif // LOCAL
	return 0;
}