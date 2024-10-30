/*
    Soheil Mohammadkhani
    Sos Goge Tabarok :)
*/
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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN];

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> A[i];
		bool turn = true;
		ll prv = -1;
		while (true) {
			ll mx_ind = -1, mx = 0;
			for (int i = 0; i < n; i++) {
				if (i != prv && A[i] > mx) mx_ind = i, mx = A[i];
			} 

			if (mx_ind < 0) {
				if (turn) cout << "HL" << endl;
				else cout << "T" << endl;
				break;
			} 

			A[mx_ind]--;
			prv = mx_ind;
			turn = !turn;
		}

	}
	return 0;
}