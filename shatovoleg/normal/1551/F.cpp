// #pragma GCC optimize("Ofast,unroll-all-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
// #pragma GCC target("popcnt")

#include <bits/stdc++.h>
#include <unistd.h>

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


const int INF = (is_same<int, ll>::value ? 1e18 + 666 : 1e9 + 666);
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

// const int MEM_SIZE = 5e8;
// char mem[MEM_SIZE];
// int cur_mem_ptr = 0;

// void* operator new(size_t n) {
//     cur_mem_ptr += n;
//     return mem + cur_mem_ptr - n;
// }

// void operator delete(void*) noexcept {}
// void operator delete(void*, size_t) noexcept {}

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
    int res = 1;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int((1ll * a * res) % mod);
            res %= mod;
        }
        a *= a;
        a %= mod;
    }
    return res;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif

void run();

signed main() {
    // UseFiles("taskname");
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
    constexpr int mod = 1e9 + 7;

    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    if (k == 2) {
        cout << (n * (n - 1) >> 1) << endl;
        return;
    }

    function<vector<int>(int, int)> dfs = [&g, &dfs](int v, int p) {
        vector<int> res;
        for (auto& x : g[v]) {
            if (x == p) continue;
            vector<int> ret = dfs(x, v);
            if (len(ret) > len(res)) {
                swap(ret, res);
            }
            for (int i = 1; i <= len(ret); ++i) {
                res[len(res) - i] += ret[len(ret) - i];
            }
        }
        res.pb(1);
        return res;
    };

    int ans = 0;
    for (int center = 0; center < n; ++center) {
        if (len(g[center]) < k) continue;
        vector<vector<int>> dverts;
        for (auto& v : g[center]) {
            dverts.pb(dfs(v, center));
            reverse(all(dverts.back()));
        }

        for (int i = 0;; ++i) {
            vector<int> dp(k + 1, 0);
            dp[0] = 1;
            for (auto& x : dverts) {
                if (len(x) <= i) continue;
                for (int j = k; j > 0; --j) {
                    dp[j] += int(1ll * dp[j - 1] * x[i] % mod);
                    if (dp[j] >= mod) {
                        dp[j] -= mod;
                    }
                }
            }
            if (dp[k] == 0) break;
            ans += dp[k];
            if (ans >= mod) {
                ans -= mod;
            }
        }
    }
    cout << ans << endl;
}