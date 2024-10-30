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
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#if ( _WIN32 || _WIN64 || __WIN32__ || __WIN64__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

inline string normalize(string s) {
    string res = "";
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            res.pb('a' + (s[i] - 'A'));
        } else {
            res.pb(s[i]);
        }
    }
    return res;
}

vi dp;
vector<pair<string, string> > R;

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string v, tmp, u;
        cin >> v >> tmp >> u;
        v = normalize(v);
        u = normalize(u);
        R.pb(mp(v, u));
    }
    dp.resize(n);
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = 1;
        for (int j = i + 1; j < n; ++j) {
            if (R[j].sc == R[i].fs) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (R[i].sc == normalize("Polycarp")) {
            ans = max(ans, dp[i]);
        }
    }
    cout << ans + 1 << endl;
    return 0;
}