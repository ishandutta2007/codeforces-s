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
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll NMAX = 1e6 + 10;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n;
vector<ll> a;
vector<ll> b;
ll bsum[NMAX] = {0};

int main() {
//    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll l;
        cin >> l;
        vector<ll> v;
        for (int i = 0; i < l; i++) {
            ll k;
            cin >> k;
            v.push_back(k);
        }

        reverse(all(v));
        if (is_sorted(all(v))) {
            a.push_back(*min_element(all(v)));
            b.push_back(*max_element(all(v)));
        }
    }

    for (ll x : b) {
        bsum[x]++;
    }

    for (int i = 1; i < NMAX; i++) {
        bsum[i] = bsum[i - 1] + bsum[i];
    }

    ll res = n * n;
    for (ll x : a) {
        res -= bsum[x];
    }

    cout << res << endl;
    return 0;
}