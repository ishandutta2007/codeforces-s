#include <cassert>
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

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1e5;

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n;
    scanf("%d", &n);
    map<int, int> x, y;
    map<pair<int, int>, int> p;
    
    forn(i, n) {
        int a, b;
        scanf("%d%d", &a, &b);
        x[a]++;
        y[b]++;
        p[pair<int, int>(a, b)]++;
    }
    ll ans = 0;
    for (auto i : x) {
        ans += ((ll)i.second) * (i.second - 1) / 2;
    }
    for (auto i : y) {
        ans += ((ll)i.second) * (i.second - 1) / 2;
    }
    for (auto i : p) {
        ans -= ((ll)i.second) * (i.second - 1) / 2;
    }
    cout << ans << '\n';
    return 0;

}