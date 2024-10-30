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
#define forr(n)                     for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
//    fast_io;
    int n;
    cin >> n;
    int ja = 0;
    bool* a = new bool[n];

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        bool b = (c == '(');
        a[i] = b;

        if (b) ja++;
    }

    if (n % 2 == 1 || ja != n / 2) {
        return cout << -1 << endl, 0;
    }

    int o = 0;
    int now = 0;
    int sum = 0;
    bool problem = false;
    for (int i = 0; i < n; i++) {
        if (a[i]) o++;
        else o--;
        if (o < 0) {
            problem = true;
            now++;
        }
        if (o == 0 && problem) {
            sum += now + 1;
            now = 0;
            problem = false;
        }
    }

    if (o != 0) return cout << -1 << endl, 0;
    cout << sum << endl;
    return 0;
}