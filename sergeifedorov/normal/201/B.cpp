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

const int nmax = 1010;

int n, m;
int a[nmax][nmax];
int64 h[nmax], r[nmax];

int calc(int64 *h, int n, int64 &res) {
    res = 1e18;
    int p = 0;
    forn(i, n + 1) {
        int64 now = 0;
        forn(j, n) {
            int64 l = max(i - j - 1, j - i) * 4 + 2;
            now += sqr(l) * h[j];
        }
        if (now < res) {
            res = now;
            p = i;
        }
    }
    return p;
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> m;
    forn(i, n) {
        forn(j, m) {
            scanf("%d", &a[i][j]);
            h[i] += a[i][j];
            r[j] += a[i][j];
        }
    }
    int64 r1, r2;
    r1 = r2 = 0;
    int x = calc(h, n, r1), y = calc(r, m, r2);
    cout << r1 + r2 << endl;
    cout << x << " " << y << endl;
    

    return 0;
}