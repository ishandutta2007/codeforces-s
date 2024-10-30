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

struct Fenv {
    vector<int> tree;

    Fenv(int n) : tree(n + 1, 0) {}

    int get(int idx) const {
        ++idx;
        int sm = 0;
        for (; idx > 0; idx -= f(idx)) {
            sm += tree[idx];
        }
        return sm;
    }

    void add(int idx, int val) {
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    for (auto& x : a) {
        cin >> x;
    }
    {
        vector<int> b(a);
        sort(all(b));
        for (auto& x : a) {
            x = int(lower_bound(all(b), x) - b.begin());
        }
    }
    Fenv t(n * m + 1);
    ll ans = 0;
    for (auto& x : a) {
        ans += t.get(x);
        t.add(x + 1, 1);
    }
    cout << ans << endl;
}