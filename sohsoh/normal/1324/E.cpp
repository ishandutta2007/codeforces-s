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
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2000 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN] = {0};

int main() {
    fast_io;
    ll n, h, l, r;
    cin >> n >> h >> l >> r;
    ll* a = new ll[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += a[i];
        for (int j = 0; j <= i; j++) {
            ll m1 = dp[i - 1][j - 1];
            ll m2 = dp[i - 1][j];
            ll m = max(m1, m2);
            ll t = (sum - j) % h;
            if (t >= l && t <= r) {
                m++;
            }

            dp[i][j] = m;
        }
    }

//    alog(dp[3], n + 1)

    cout << *max_element(dp[n], dp[n] + n + 1) << endl;
    return 0;
}