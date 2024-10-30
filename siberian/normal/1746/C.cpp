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

void check(int n, vector<int> a, vector<int> ans) {
    cout.flush();
    for (int i = 0; i < n; ++i) {
        for (int j = ans[i]; j < n; ++j) {
            a[j] += i + 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        assert(a[i - 1] <= a[i]);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vin(a);
    vector<int> ans(n);
    set<int> has;
    for (int i = 1; i <= n; ++i) {
        has.insert(i);
    }
    for (int i = 0; i + 1 < n; ++i) {
        int diff = a[i] - a[i + 1];
        auto it = has.lower_bound(diff);
        assert(it != has.end());
        ans[(*it) - 1] = i + 1;
        has.erase(it);
    }
    ans[(*has.begin()) - 1] = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << ans[i] + 1;
    } 
    cout << '\n';
    // check(n, a, ans);
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