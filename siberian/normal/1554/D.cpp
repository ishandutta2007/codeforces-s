#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(a) (a).begin(), (a).end()

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
	if (y < x) {
		x = y;
	}
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
	if (x < y) {
		x = y;
	}
}

void solve() {
	int n;
	cin >> n;
	string ans = "";
	if (n & 1) {
		ans += 'z';
		n--;
	}
	if (n > 0) {
		int cntL = n / 2;
		int cntR = n / 2 - 1;
		for (int i = 0; i < cntL; ++i) {
			ans += 'a';
		}
		ans += 'b';
		for (int i = 0; i < cntR; ++i) {
			ans += 'a';
		}
	}
	cout << ans << '\n';
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