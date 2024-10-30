#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

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

template <class T> T sqr (T x) {return x * x;}

int n;
int a[100500];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &a[i]);
	int ans = 1 + a[1] * a[1];
	for (int d = 1; d < n; d++) {
		if (d * d >= ans) break;
		int s = 0;
		int q = inf;
		int l = 1;
		int r = d + 1;
		forn (j, d)
			s += a[j + 1];
		q = min(q, abs(s));
		while (r < n) {
			s -= a[l];
			s += a[r];
			l++;
			r++;
			q = min(q, abs(s));
		}
		if ((int64)q * q + (int64)d * d < ans)
			ans = q * q + d * d;
	}
	cout << ans << endl;
	return 0;
}