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

const int nmax = 2e6 + 1e5;

int n;
int a[nmax];


int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);


    cin >> n;
    forn(i, n)
        a[i] = i;
    int st = 0;
    for (int i = 2; i <= n; i ++) {
        int now = a[st];
        for (int j = 0; j < n; j += i) {
            int pos = min(st + j + i, st + n);
            int buf = a[pos];
            a[pos] = now;
            now = buf;
        }
        st ++;
    }
    forn(i, n)
        printf("%d ", a[st + i] + 1);
        puts("");

    return 0;
}