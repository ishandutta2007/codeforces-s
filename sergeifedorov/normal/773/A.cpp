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
#include <bitset>
#include <sstream>
#include <queue>

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

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 1700;

int main ()
{
	//  freopen("input.txt", "rt", stdin);
	//  freopen("output.txt", "wt", stdout);
	
	int tst;
	cin >> tst;
	for (int qwe = 0; qwe < tst; qwe ++) {
		long long x, y, p, q;
		cin >> x >> y >> p >> q;
		if (p == 0) {
			if (x == 0) {
				puts("0");
				continue;
			}
			puts("-1");
			continue;
		}
		long long t1 = y * p - x * q;
		long long t2 = q - p;
		if (t2 == 0) {
			if (t1 == 0)
				puts("0");
			else
				puts("-1");
			continue;
		}
		long long k = (t1 + t2 - 1) / t2;
		k = max(k, (x * q - y * p + p - 1) / p);
		k = max(k, 0ll);
		// cout << k << endl;
		k += (q - (y + k) % q) % q;
		cout << k << endl;
	}

	return 0;
}