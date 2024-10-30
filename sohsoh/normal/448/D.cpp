/*
    Soheil Mohammadkhani
    IDK :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9

ll n, m, k;

ll calc(ll x) {
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        s += min((x - 1) / i, m);
    }

    return s;
}

int main() {
//    fast_io;
    cin >> n >> m >> k;
    if (n > m) swap(n, m);
    ll mn = 1,  mx = n * m;
    while (mn < mx) {
        ll mid = (mn + mx) / 2;
        if (mx - mn == 1) {
            if (calc(mx) >= k) return cout << mn << endl, 0;
            else return cout << mx << endl, 0;
        }

        if (calc(mid) >= k) {
            mx = mid - 1;
        } else {
            mn = mid;
        }
    }

    cout << mn << endl;
    return 0;
}