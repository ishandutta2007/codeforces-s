#include <bits/stdc++.h>
using namespace std;
#define K(x...)                        \
  {                                    \
    cerr << "BEGIN    " << #x << "->"; \
    Err(x);                            \
    cerr << "   END" << endl;          \
  }
void Err() {}
template <class T, class... A>
void Err(T a, A... x) {
  cerr << a << ',';
  Err(x...);
}
template <class X, class Y, class... A>
void Err(pair<X, Y> a, A... x) {
  cerr << '(' << a.first << ',' << a.second << "),";
  Err(x...);
}
template <template <class...> class T, class t, class... A>
void Err(T<t> a, A... x) {
  cerr << a.size() << ":{";
  for (auto v : a) Err(v);
  cerr << "},";
  Err(x...);
}
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
template <class T>
void Min(T &a, const T b) {
  if (a > b) a = b;
}
template <class T>
void Max(T &a, const T b) {
  if (a < b) a = b;
}
#define fi first
#define se second
#define lo (o << 1)
#define ro (o << 1 | 1)
#define mid (l + r >> 1)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a, b, c)
#define K(a...)
#endif
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10, M = 500;
const ll mod = 1e9 + 7;
const ld eps = 1e-8;
const ld PI = acos(-1);
int sgn(ld a) { return a < -eps ? -1 : (a < eps ? 0 : 1); }

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("a.in", "r", stdin);
  int _;cin>>_;
  while(_--){
    int n;cin>>n;
    if(n%3==0)cout<<n/3<<endl;
    else if(n%3==2)cout<<n/3+1<<endl;
    else if(n==1)cout<<2<<endl;
    else cout<<n/3+1<<endl;
  }
}