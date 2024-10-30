// #include <atcoder/all>
#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

ll a, b, c, d;

bool f(ll mid) {
    if(mid * d > c) {
        return false;
    } else
        return mid * d * b < a;
}

void solve() {
    cin >> a >> b >> c >> d;

    if(a > c * b) {
        cout << "-1\n";
        return;
    }

    ll l = 0, r = 1000000;
    while(l + 1 < r) {
        ll mid = l + r >> 1;
        (f(mid) ? l : r) = mid;
    }

    ll ans = a * (l + 1) - l * (l + 1) / 2 * d * b;

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}