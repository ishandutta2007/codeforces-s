#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (n%i == 0) ans++;
	}
	cout << ans << endl;
	cin >> n;
}