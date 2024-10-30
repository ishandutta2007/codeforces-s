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
const string task = "";

template <class T> T sqr (T x) {return x * x;}

const int nmax = 100100;
int n, m;
int res[nmax];
vector<pii> x;

int main ()
{
	cin >> n >> m;
	int now = 0;
	forn(q, n){
		int t, x1;
		scanf("%d %d", &t, &x1);
		x.pb(mp(x1, q));
		if (q == n - 1 || x.size() == m){
			now = max(now, t);
			sort(all(x));
			forn(i, x.size()){
				now += (x[i].fs - ((i == 0) ? 0 : x[i-1].fs));
				int j = i;
				while (j < x.size() && x[j].fs == x[i].fs) j ++;
				for (int w = i; w < j; w ++)
					res[x[w].sc] = now;
				now += (j - i) / 2 + 1;
				i = j - 1;
			}
			now += x.back().fs;
			x.clear();
		}
	}
	forn(i, n)
		printf("%d ", res[i]);
	puts("");
		

	return 0;
}