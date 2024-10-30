#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a -= b;
	if (a <= 0) {
		cout << b << endl;
		return;
	}
	if (c <= d) {
		cout << -1 << endl;
		return;
	}
	int x = c - d;
	int ans = (a + x - 1) / x;
	ans *= c;
	ans += b;
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}