#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	ll n;
	cin >> n;
	while (true) {
		ll d = n;
		bool good = true;
		while (d) {
			int t = d % 10;
			if (t && n % t) {
				good = false;
				break;
			}
			d /= 10;
		}
		if (good) {
			cout << n << "\n";
			return;
		}
		++n;
	}
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}