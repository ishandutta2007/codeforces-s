/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10; // Change it
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

void win(bool b) {
    if (b) cout << "FastestFinger" << endl;
    else cout << "Ashishgup" << endl;
}

bool is_prime(ll x) {
    ll sq = sqrt(x);
    if (x == 1) return false;
    for (int i = 2; i <= sq; i++) if (x % i == 0) return false;
    return true;
}

ll solve() {
    ll n;
    cin >> n;
    if (n == 1) return win(true), 0;
    if (n == 2) return win(false), 0;
    if (n % 2) return win(false), 0;
    if (n % 4 == 0) {
        while (n % 2 == 0) n /= 2;
        if (n == 1) win(true);
        else win(false);
        return 0;
    }

    n /= 2;
    if (!is_prime(n)) return win(false), 0;
    win(true);
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}