#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	string t;
	cin >> t;
	int n = s.length();
	int c = 0;
	for (char i: t) if (i == 'a') ++c;
	if (t == "a") cout << "1\n";
	else if (c >= 1) cout << "-1\n";
	else cout << (1ll << n) << "\n";
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