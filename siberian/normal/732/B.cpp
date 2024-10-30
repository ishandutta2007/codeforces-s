#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, k;
	cin >> n >> k; 
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int have = a[i] + a[i + 1];
		if (have >= k) continue;
		ans += k - have;
		a[i + 1] += k - have;
	}
	cout << ans << endl;
	for (auto i : a) cout << i << " ";
		
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}