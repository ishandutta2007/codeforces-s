#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n > 2 || n == 2 && s[0] == s[1]) cout << "NO\n";
	else cout << "YES\n";
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