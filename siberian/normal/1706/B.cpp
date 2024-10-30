#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vin(a);
    vector<int> ans(n, 0);
    vector<vector<int>> cur_cnt(2, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        --a[i];
        chkmax(cur_cnt[i % 2][a[i]], cur_cnt[(i % 2) ^ 1][a[i]] + 1);
        chkmax(ans[a[i]], cur_cnt[i % 2][a[i]]);
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}