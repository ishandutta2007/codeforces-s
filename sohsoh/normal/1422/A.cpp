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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll A[3];
		cin >> A[0] >> A[1] >> A[2];
		sort(A, A + 3);
		if (A[0] == A[2]) cout << A[0] << endl;
		else if (A[0] == A[1]) cout << A[2] << endl;
		else if (A[0] == A[2]) cout << A[1] << endl;
		else if (A[1] == A[2]) cout << A[0] << endl;
		else cout << A[2] << endl;
	}
	return 0;
}