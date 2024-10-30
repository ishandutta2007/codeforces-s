/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
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
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5e5 + 10; // CHANGE :)
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

ll fact[MAXN], inv[MAXN];

void prep() {
    fact[0] = 1;
    inv[0] = 1;

    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = poww(fact[i], MOD - 2, MOD) % MOD;
    }
}

ll C(ll k, ll n) {
    return fact[n] * inv[n - k] % MOD * inv[k] % MOD;
}

int main() {
    fast_io;
    ll n, k;
    cin >> n >> k;
    prep();
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll x = n / i;
        if (k > x) break;
        ans += C(k - 1, x - 1) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}