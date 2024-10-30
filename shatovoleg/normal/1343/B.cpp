// #pragma GCC optimize("Ofast,unroll-all-loops")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define mp make_pair
#define int ll

#define debug(x) cout << #x << " = " << x << endl;

const int INF = (is_same<int, ll>::value ? 1e18 + 666 : 1e9 + 666);

// const int MEM_SIZE = 1e8;
// char mem[MEM_SIZE];
// int cur_mem_ptr = 0;

// void* operator new(size_t n) {
//     cur_mem_ptr += n;
//     return mem + cur_mem_ptr - n;
// }

// void operator delete(void*) noexcept {}
// void operator delete(void*, size_t) noexcept {}

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
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
    // UseFiles("squads");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void solve() {
    int n;
    cin >> n;
    if (n & 3) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < (n >> 2); ++i) {
        int val = 2 * i + 3;
        --val;
        cout << val << " ";
    }
    for (int i = (n >> 2); i < (n >> 1); ++i) {
        int val = 2 * i + 3;
        ++val;
        cout << val << " ";
    }
    for (int i = 0; i < (n >> 1); ++i) {
        cout << 2 * i + 3 << " ";
    }
    cout << endl;
}

void run() {
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}