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

// #define TASK "codes"

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
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    vector<array<int, 3>> ans;
    for (int i = 0; i < n; ++i) {
        int j = int(min_element(i + all(a)) - a.begin());
        if (i == j) continue;
        ans.pb({i + 1, j + 1, j - i});
        rotate(a.begin() + i, a.begin() + j, a.begin() + j + 1);
    }
    cout << len(ans) << endl;
    for (auto& [l, r, s] : ans) {
        cout << l << " " << r << " " << s << endl;
    }
}