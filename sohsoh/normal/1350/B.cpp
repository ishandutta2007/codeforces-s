/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, vector<ll>> plv;
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
#define alog(a, n)                  for (ll i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (ll i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD =  998244353; // 1e9 + 9;

ll a[MAXN], n;


ll f_ans(ll ind, ll s = 0) {
    ll bf = 0;
    for (int i = 2; i * ind <= n; i++) {
        ll j = ind * i;
        if (a[j] <= a[ind]) continue;
        bf = max(bf, f_ans(j, s + 1) + 1);
    }

    return bf;
}

ll solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll bf = 0;
    for (int i = 1; i <= n; i++) {
        bf = max(bf, f_ans(i));
    }

    return cout << bf + 1 << endl, 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}