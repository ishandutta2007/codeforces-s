#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

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
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 2; j < n; ++j) {
            if (s[i] != s[j]) continue;
            for (int k = i + 1; k < j; ++k) {
                if (s[i] != s[k]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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