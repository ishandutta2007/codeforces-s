#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

// ========================================================================= //

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ipair> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i].Y;
    for (int i = 0; i < n; ++i)
      cin >> a[i].X;
    sort(all(a), greater<ipair>());

    long long ans = 0;
    set<lpair> segs;
    for (ipair aa : a) {
      ll cost = aa.X;
      ll v = aa.Y;
      ll nv = v;
      auto it = segs.lower_bound(lpair({v, LINF}));
      if (it != segs.begin()) {
        --it;
        if (it->Y >= v) {
          nv = it->Y + 1;
        }
      }
      ans += (nv - v) * cost;
      it = segs.insert({nv, nv}).first;
      if (it != segs.begin()) {
        --it;
        ll l = it->X;
        ll r = it->Y;
        if (r + 1 == nv) {
          segs.erase(it);
          segs.erase({nv, nv});
          it = segs.insert({l, nv}).first;
        } else {
          ++it;
        }
      }
      ll cl = it->X;
      ++it;
      if (it != segs.end()) {
        ll l = it->X;
        ll r = it->Y;
        if (l - 1 == nv) {
          it = segs.erase(it);
          --it;
          segs.erase(it);
          it = segs.insert({cl, r}).first;
        }
      }
    }
    cout << ans << "\n";


    return 0;
}