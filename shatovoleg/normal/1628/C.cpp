#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
// #define int ll


const int INF = (is_same<int, ll>::value ? 3e18l + 666 : 1e9 + 666);
const ll INFll = 3e18l + 666;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

inline int bpow(ll a, ll b, int mod) {
    a %= mod;
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int(1ll * res * a % mod);
        }
        a *= a;
        a %= mod;
    }
    return res;
}

void run();

// #define TASK "taskname"

signed main() {
#if defined(TASK) && !defined(LOCAL)
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void solve();

void run() {
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}

void solve() {
    constexpr array<pii, 4> dir = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    int n;
    cin >> n;
    vector<vector<int>> fld(n, vector<int>(n));
    for (auto& line : fld) {
        for (auto& x : line) {
            cin >> x;
        }
    }
    vector<vector<char>> cov(n, vector<char>(n, 0));
    int res = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool good = true;
            for (auto [dx, dy] : dir) {
                if (i + dx < 0 || i + dx >= n || j + dy < 0 || j + dy >= n) continue;
                if (cov[i + dx][j + dy]) {
                    good = false;
                    break;
                }
            }
            if (!good) continue;
            res ^= fld[i][j];
            for (auto [dx, dy] : dir) {
                if (i + dx < 0 || i + dx >= n || j + dy < 0 || j + dy >= n) continue;
                cov[i + dx][j + dy] = 1;
                ++cnt;
            }
        }
    }
    assert(cnt == n * n);
    cout << res << endl;
}