#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, A[MAXN], k;
int solve() {
	cin >> n >> k;
	int lst = 0;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (A[i] != i) lst = i;
	}
	
	ld noans = 1;
	for (int i = 0; i < k; i++) {
		double r, p;
		cin >> r >> p;
		if (r >= lst) {
			noans *= (ld(1) - p);
		}
	}

	cout << setprecision(10) << fixed << endl;
	if (lst == 0) return cout << 1.0 << endl, 0;
	cout << ld(1) - noans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}