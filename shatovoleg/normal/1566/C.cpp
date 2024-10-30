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


const int INF = (is_same<int, ll>::value ? 1e18l + 666 : 1e9 + 666);
const ll INFll = 1e18 + 666;
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

// #define TASK "mining"

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
    int n;
    cin >> n;
    vector<string> fld(2);
    for (auto& x : fld) {
        cin >> x;
    }
    vector<string> f(n);
    for (int i = 0; i < n; ++i) {
        f[i] += fld[0][i];
        f[i] += fld[1][i];
        sort(all(f[i]));
    }
    int ans = 0;
    int mask = 0;
    for (int i = 0; i < n; ++i) {
        if (f[i] == "11") {
            mask |= 2;
            if (mask == 3) {
                ans += 2;
                mask = 0;
            }
        } else if (f[i] == "01") {
            if (mask == 1) {
                ans += 1;
            }
            mask = 0;
            ans += 2;
        } else {
            if (mask == 1) {
                ans += 1;
            }
            mask |= 1;
            if (mask == 3) {
                ans += 2;
                mask = 0;
            }
        }
    }
    if (mask & 1) {
        ans += 1;
    }
    cout << ans << '\n';
}