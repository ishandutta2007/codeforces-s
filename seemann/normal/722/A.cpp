#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 1e5;

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int s;
    int h, m;
    scanf("%d", &s);
    scanf("%d:%d", &h, &m);
    int ans = 0;
    if (m / 10 > 5) {
        m = m % 10;
    }
    if (s == 24) {
        if (h > 23) {
            h = h % 10;
        }
    } else {
        if (h > 12) {
            if (h % 10 != 0) {
                h = h % 10;
            } else {
                h = 10;
            }
        } else if (h == 0) {
            h = 1;
        }
    }
    printf("%02d:%02d", h, m);
    return 0;
}