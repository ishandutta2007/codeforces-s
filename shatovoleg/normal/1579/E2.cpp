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

struct Fenv {
    vector<int> tree;

    Fenv(int n) : tree(n + 1, 0) {}

    int get(int idx) const {
        int res = 0;
        ++idx;
        for (; idx > 0; idx -= f(idx)) {
            res += tree[idx];
        }
        return res;
    }

    void plus(int idx, int val) {
        ++idx;
        for (; idx < len(tree); idx += f(idx)) {
            tree[idx] += val;
        }
    }

    static int f(int i) {
        return i & -i;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    {
        vector<int> id(v);
        sort(all(id));
        id.resize(unique(all(id)) - id.begin());
        for (auto& x : v) {
            x = int(lower_bound(all(id), x) - id.begin());
        }
    }
    Fenv t(n);
    ll ans = 0;
    int cnt = 0;
    for (auto& x : v) {
        int l = t.get(x - 1), r = cnt - t.get(x);
        ans += min(l, r);
        t.plus(x, 1);
        ++cnt;
    }
    cout << ans << endl;
}