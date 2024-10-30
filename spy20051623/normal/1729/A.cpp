#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a, b, c;
	std::cin >> a >> b >> c;
	if (a < abs(b - c) + c) std::cout << "1\n";
	else if (a > abs(b - c) + c) std::cout << "2\n";
	else std::cout << "3\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}