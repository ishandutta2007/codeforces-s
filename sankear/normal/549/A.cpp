#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(x) (x).begin(), (x).end()
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || _WIN64 || __WIN32__ || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define end _end

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef long double ld;
typedef complex<double> tc;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 55;

char a[N][N];

inline bool check(char a, char b, char c, char d) {
    char s[5] = { a, b, c, d, 0 };
    sort(s, s + 4);
    return string(s) == "acef";
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %c", &a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            if (check(a[i][j], a[i][j + 1], a[i + 1][j], a[i + 1][j + 1])) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}