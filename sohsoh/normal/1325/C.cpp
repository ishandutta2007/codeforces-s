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
    int n;
    cin >> n;
    pair<int, int>* c = new pair<int, int>[n + 1];
    forr(n + 1) c[i] = make_pair(0, i);
    pair<int, int>* cash = new pair<int, int>[n - 1];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        c[u].first++;
        c[v].first++;

        cash[i] = make_pair(u, v);
    }

    pair<int, int> m = *max_element(c, c + n + 1);
    int f = m.first;
    int ff = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = cash[i].first;
        int v = cash[i].second;

        if (u == m.second || v == m.second) {
            cout << ff << endl;
            ff++;
        } else {
            cout << f << endl;
            f++;
        }
    }
}