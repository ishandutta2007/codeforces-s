#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int n, k;
int a[5050];
map<int, int> st;

void solve() {
	int s;
	scanf("%d", &s);
	int ans = k + 1;
	forn(i, n)
		for (int j = 1; j <= k; j++) {
			int x = a[i] * j;
			if (x > s) continue;
			if (x == s) ans = min(ans, j);
			int y = s - x;
			map<int, int> ::iterator it = st.find(y);
			if (it == st.end()) continue;
			ans = min(ans, j + it->second);
		}
	if (ans == k + 1) ans = -1;
	printf("%d\n", ans);
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	forn(i, n) {
		scanf("%d", &a[i]);
		for (int j = 1; j <= k; j++) {
			int x = a[i] * j;
			if (st.count(x))
				st[x] = min(st[x], j);
			else
				st[x] = j;
		}
	}
	int q;
	scanf("%d", &q);
	forn(i, q) solve();
	return 0;
}