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
void solve();

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

void solve() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    if(sx == tx || sy == ty) {
        cout << (abs(sx - tx) + abs(sy - ty)) << "\n";
    } else {
        cout << abs(sx - tx) + abs(sy - ty) + 2 << "\n";
    }
}