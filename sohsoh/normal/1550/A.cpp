// Sohsoh84 :)))))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll s;
		cin >> s;
		ll x = 1, ans = 0;
		while (s > 0) {
			s -= x;
			x += 2;
			ans++;
		}

		cout << ans << endl;
	}
	return 0;
}