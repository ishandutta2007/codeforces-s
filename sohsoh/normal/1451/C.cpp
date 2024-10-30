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

int A[26], B[26], n, k;
string s1, s2;

int solve() {
	memset(A, 0, sizeof A);
	memset(B, 0, sizeof B);
	cin >> n >> k >> s1 >> s2;
	for (char c : s1) A[c - 'a']++;
	for (char c : s2) B[c - 'a']++;
	for (int i = 0; i < 25; i++) {
		if (A[i] < B[i]) return cout << "NO" << endl, 0;
		ll diff = A[i] - B[i];
		if (diff % k > 0) return cout << "NO" << endl, 0;
		A[i + 1] += diff;	
	}

	cout << "YES" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}