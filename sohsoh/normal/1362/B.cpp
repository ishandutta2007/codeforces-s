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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll a[MAXN], cnt[MAXN], tcnt[MAXN];
ll solve() {
    ll n;
    cin >> n;
    fill(cnt, cnt + 1025, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    ll ans = -1;
    for (int k = 1; k < 1025; k++) {
        fill(tcnt, tcnt + 1025, 0);
        for (int i = 0; i < n; i++) {
            tcnt[a[i] ^ k]++;
        }

        bool b = true;
        for (int i = 0; i < 1025; i++) {
            if (tcnt[i] != cnt[i]) {
                b = false;
                break;
            }
        }

        if (b) return cout << k << endl, 0;
    }

    cout << "-1" << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}