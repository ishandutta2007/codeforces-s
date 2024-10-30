/*
    Soheil Mohammadkhani
    Generated by myself :|
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

const ll MAXN = 1e6 + 10; // Change it :)
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, A[MAXN], k;
map<ll, ll> cnt;

ll solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        ll md = k - (A[i] % k);
        if (md == k || md == 0) continue;
        if (cnt.find(md) != cnt.end()) cnt[md]++;
        else cnt.insert({md, 0});
    }

    ll ans = 0;
    for (pll e : cnt) {
        ans = max(ans, e.Y * k + e.X + 1);
    }
    cout << ans << endl;
    cnt.clear();
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}