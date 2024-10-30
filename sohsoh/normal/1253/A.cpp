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

ll A[MAXN], B[MAXN];

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];

        ll diff = -1;
        bool used = false, avai = true, can = true;
        for (int i = 0; i < n; i++) {
            if (A[i] == B[i]) {
                if (diff > -1) avai = false;
                continue;
            }

            if (B[i] < A[i]) can = false;

            if (diff == -1) diff = B[i] - A[i];
            if (B[i] - A[i] != diff) can = false;
            if (!avai) can = false;
        }

        if (can) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}