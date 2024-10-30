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

ll n, A[MAXN], B[MAXN];

bool cmp(ll i, ll j) { return A[i] > A[j]; }

int main() {
    fast_io;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i], B[i] = i;
    sort(B + 1, B + n + 1, cmp);
    sort(A + 1, A + n + 1);
    reverse(A + 1, A + n + 1);

    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += A[i] * (i - 1) + 1;
    cout << ans << endl;
    for (int i = 1; i <= n; i++) cout << B[i] << sep;
    cout << endl;
    return 0;
}