#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
 
#define pper(a) cerr << #a << " = " << a << endl;
 
void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }
 
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
 
template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}
 
template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}
 
template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }
 
template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}
 
mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}
 
const int mod = 998244353;
 
void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}
 
void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}
 
int mult(int a, int b) {
  return a * (ll)b % mod;
}
 
int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}
 
int n;
const int N = 2e5 + 7;
struct Tree {
  int t[2 * N];
 
 
  void change(int p, int x) {
    p += n;
    while (p) {
      add(t[p], x);
      p /= 2;
    }
  }
 
  int get(int l, int r) {
    int res = 0;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l % 2 == 1) {
        add(res, t[l++]);
      }
      if (r % 2 == 0) {
        add(res, t[r--]);
      }
    }
    return res;
  }
} tree;
 
int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
  cin >> n;
 
  vector <int> pos(n);
  vector <int> to(n);
  vector <int> active(n);
 
  for (int i = 0; i < n; ++i) {
    cin >> pos[i] >> to[i] >> active[i];
  }
 
  vector <int> ans(n, 0);
 
  for (int i = 0; i < n; ++i) {
    int a = lower_bound(all(pos), to[i]) - pos.begin();
    int sum = (pos[i] - to[i]) % mod;
    if (a != i) {
      add(sum, tree.get(a, i - 1));
    }
    ans[i] = sum;
    tree.change(i, sum);
  }
 
  int res = 0;
  int ppos = 0;
  for (int i = 0; i < n; ++i) {
    add(res, (pos[i] - ppos) % mod);
    ppos = pos[i];
    if (active[i]) {
      add(res, ans[i]);
    }
  }
  add(res, 1);
  cout << res << "\n";
}