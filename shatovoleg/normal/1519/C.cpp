// #pragma GCC optimize("Ofast,unroll-all-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
// #pragma GCC target("popcnt")

#include <bits/stdc++.h>

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

inline int bpow(int a, int b, int mod) {
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res *= a;
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

void solve() {
    int n;
    cin >> n;
    vector<vector<ll>> teams(n);
    {
        vector<pii> students(n);
        for (auto& [u, _] : students) {
            cin >> u;
            --u;
        }
        for (auto& [u, s] : students) {
            cin >> s;
            teams[u].pb(s);
        }
    }
    for (auto& t : teams) {
        sort(all(t));
        t.insert(t.begin(), 0);
        partial_sum(all(t), t.begin());
    }
    vector<ll> ans(n, 0);
    for (auto& t : teams) {
        for (int i = 0; i + 1 < len(t); ++i) {
            ans[i] += t.back() - t[(len(t) - 1) % (i + 1)];
        }
    }
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

void run() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}