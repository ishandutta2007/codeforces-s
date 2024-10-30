/*
    Soheil Mohammadkhani
    Generated by myself :|
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

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

vector<ll> both, alice, bob;
queue<ll> q1, q2;
ll n, k;

int main() {
    fast_io;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll t, a, b;
        cin >> t >> a >> b;
        if (a && b) both.push_back(t);
        else if (a) alice.push_back(t);
        else if (b) bob.push_back(t);
    }

    if (both.size() + min(alice.size(), bob.size()) < k) return cout << -1 << endl, 0;
    sort(all(both));
    sort(all(alice));
    sort(all(bob));
    for (ll e : both) q1.push(e);
    auto it1 = alice.begin(), it2 = bob.begin();
    while (it1 != alice.end() && it2 != bob.end()) {
        q2.push((*it1) + (*it2));
        it1++;
        it2++;
    }

    ll ans = 0;
    for (int i = 0; i < k; i++) {
        if ((!q2.empty()) && (q1.empty() || q1.front() > q2.front())) {
            ans += q2.front();
            q2.pop();
        } else {
            ans += q1.front();
            q1.pop();
        }
    }

    cout << ans << endl;
    return 0;
}