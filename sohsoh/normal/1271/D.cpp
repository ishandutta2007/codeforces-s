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

const ll MAXN = 5000 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, k, A[MAXN], B[MAXN], C[MAXN] = {0}, D[MAXN], dp[MAXN][MAXN];
vector<ll> S[MAXN];

int main() {
    fast_io;

    for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) dp[i][j] = -INF;

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i] >> C[i];
        D[i] = i;
    }

    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        D[v] = max(D[v], u);
    }

    for (int i = 1; i <= n; i++) {
        S[D[i]].push_back(i);
    }

//    for (int i = 0; i <= n; i++) {
//        cout << i << ": ";
//        for (ll u : S[i]) cout << u << sep;
//        cout << endl;
//    }


    dp[0][k] = 0;
    for (ll i = 0; i <= n; i++) {
        for (ll d : S[i]) {
            for (int j = 0; j + 1 < MAXN; j++) {
                dp[i][j] = max(dp[i][j], dp[i][j + 1] + C[d]);
            }
        }

        for (int j = A[i + 1]; j + B[i + 1] < MAXN; j++) {
            ll war = j + B[i + 1];
            dp[i + 1][war] = max(dp[i + 1][war], dp[i][j]);
        }
    }

    ll res = *max_element(dp[n], dp[n] + MAXN);
    if (res < 0) return cout << -1 << endl, 0;
    cout << res << endl;


    return 0;
}