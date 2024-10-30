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
const ll LOG = 70;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n;
ll dig[LOG] = {0};

ll f(ll n) {
    ll j = 0;
    while (n > 0) {
        if (n % 2 == 1) dig[j]++;
        n /= 2;
        j++;
    }
}

ll score(ll n) {
    ll j = 0;
    bitset<LOG> s;
    while (n > 0) {
        if (n % 2 == 1 && dig[j] == 1) {
            s[j] = 1;
        } else {
            s[j] = 0;
        }
        n /= 2;
        j++;
    }

    return s.to_ullong();
}

int main() {
    fast_io;
    cin >> n;
    ll* a = new ll[n];
    pll* b = new pll[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f(a[i]);
    }

    for (int i = 0; i < n; i++) {
        b[i] = {score(a[i]), a[i]};
    }

    sort(b, b + n);
    reverse(b, b + n);

    for (int i = 0; i < n; i++) {
        cout << b[i].Y << " ";
    }

    cout << endl;
    return 0;
}