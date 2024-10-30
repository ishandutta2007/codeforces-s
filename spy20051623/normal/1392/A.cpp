#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		if (a[i] != a[0]) {
			ok = false;
			break;
		}
	}
	if (ok) cout << n << '\n';
	else cout << "1\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}