/*
    Soheil Mohammadkhani
    Loading Text ... please wait
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
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

//KeepCalm and just code until the contest :|

ll n;
bool vis[MAXN] = {false};
vector<ll> ch[26], adj[MAXN];

void blablabla(ll j) {
    string s;
    cin >> s;
    bool arr[26] = {false};
    for (char c : s) {
        arr[c - 'a'] = true;
    }

    for (int i = 0; i < 26; i++) if (arr[i]) ch[i].push_back(j);
}

void prep_adj() {
    for (int i = 0; i < 26; i++) {
        if (SZ(ch[i]) < 2) continue;
        ll x = ch[i].back();
        ch[i].pop_back();
        for (ll e : ch[i]) {
            adj[e].push_back(x);
            adj[x].push_back(e);
        }
    }
}

void DFS(ll v) {
    vis[v] = true;
    for (ll e : adj[v]) if (!vis[e]) DFS(e);
}

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++) {
        blablabla(i);
    }

    prep_adj();

    ll s = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            DFS(i);
            s++;
        }
    }

    cout << s << endl;
    return 0;
}