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

#define int ll

int n;
vector<int> a;

int solve(int pos) {
    int cur = upper_bound(all(a), a[pos]) - a.begin();
    int ans = cur - pos;
    while (cur < n) {
        int diff = (a[cur] - a[pos]) * 2LL;
        ++ans;
        cur = lower_bound(all(a), a[pos] + diff) - a.begin();
    }
    return ans;
}

void solve() {
    cin >> n;
    a.resize(n);
    vin(a);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        chkmax(ans, solve(i));
    }
    cout << n - ans << '\n';
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