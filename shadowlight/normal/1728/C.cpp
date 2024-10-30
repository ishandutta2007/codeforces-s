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

const int mod = 1000000007;

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

void solve() {
  int res = 0;

  int n;
  cin >> n;
  multiset<int> q;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    q.insert(x);
  }
  vector<int> cnt1(10, 0);
  vector<int> cnt2(10, 0);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (q.find(x) != q.end()) {
      q.erase(q.find(x));
      continue;
    }
    int len = 0;
    int xx = x;
    do {
      ++len, xx /= 10;
    } while(xx);
    if (len > 1) {
      ++res;
      ++cnt2[len];
    } else {
      ++cnt2[x];
    }
  }
  while (q.size() && *q.rbegin() >= 10) {
    int len = 0;
    int x = *q.rbegin();
    q.erase(q.find(x));
    while (x) {
      ++len, x /= 10;
    }
    ++res;
    ++cnt1[len];
  }
  for (int x : q) {
    ++cnt1[x];
  }

  //per(res, cnt1, cnt2);

  for (int i = 2; i < 10; ++i) {
    int a = min(cnt1[i], cnt2[i]);
    int d = cnt1[i] + cnt2[i] - 2 * a;
    res += d;
  }
  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }
}