#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << (n + 4) / 5 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 1;
	for (int i = 1; i < T; i++) solve();	
#endif
}