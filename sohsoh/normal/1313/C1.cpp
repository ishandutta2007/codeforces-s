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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
    fast_io;
    ll n;
    cin >> n;

    ll* a = new ll[n];
    ll* best_res = new ll[n];
    ll* res = new ll[n];
    fill(res, res + n, 0);

    ll m = 0;
    ll mi = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        res[i] = a[i];
        ll mh = a[i];
        ll sum = a[i];
        for (int j = i + 1; j < n; j++) {
            mh = min(mh, a[j]);
            sum += min(mh, a[j]);

            res[j] = min(mh, a[j]);
        }

        mh = a[i];
        for (int j = i - 1; j >= 0; j--) {
            mh = min(mh, a[j]);
            sum += min(mh, a[j]);

            res[j] = min(mh, a[j]);
        }

        if (m < sum) {
            m = sum;
            mi = i;
        }
    }

    int i = mi;
    res[i] = a[i];
    ll mh = a[i];
    ll sum = a[i];
    for (int j = i + 1; j < n; j++) {
        mh = min(mh, a[j]);
        sum += min(mh, a[j]);

        res[j] = min(mh, a[j]);
    }

    mh = a[i];
    for (int j = i - 1; j >= 0; j--) {
        mh = min(mh, a[j]);
        sum += min(mh, a[j]);

        res[j] = min(mh, a[j]);
    }
    alog(res, n);
    return 0;
}