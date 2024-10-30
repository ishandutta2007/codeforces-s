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
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n;

ll a[MAXN] = {0};
priority_queue <pll, vector<pll>, greater<pll>> pq;

int main() {
    fast_io;

    cin >> n;
    for (int i = 0; i < n; i++) {
        ll k;
        cin >> k;
        a[i] = k;
        pq.push({k, i});
    }

    ll ans = n;

    while (!pq.empty()) {
        pll x = pq.top();
        pq.pop();
        if (!pq.empty() && pq.top().X == x.X) {
            pll y = pq.top();
            pq.pop();
            ans--;
            a[x.Y] = 0;
            a[y.Y] = 2 * a[y.Y];
            pq.push({a[y.Y], y.Y});
        }
    }

    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) cout << a[i] << sep;
    }

    cout << endl;
    return 0;
}