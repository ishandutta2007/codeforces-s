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

const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector <vector <int>> dp(n + 1, vector<int>(2, INF));
  dp[1][0] = 0;
  dp[1][1] = 0;
  if (s[0] == 'B') {
    dp[1][0] = INF;
  } else if (s[0] == 'R') {
    dp[1][1] = INF;
  }

  for (int i = 1; i < n; ++i) {
    int k;
    if (s[i] == 'B') {
      k = 1;
    } else if (s[i] == 'R') {
      k = 0;
    } else {
      k = -1;
    }

    if (k != 1) dp[i + 1][0] = min(dp[i][1], dp[i][0] + 1);
    if (k != 0) dp[i + 1][1] = min(dp[i][1] + 1, dp[i][0]);
  }

  int val = (dp[n][0] < dp[n][1] ? 0 : 1);

  for (int i = n - 1; i >= 0; --i) {
    if (!val) {
      s[i] = 'R';
    } else {
      s[i] = 'B';
    }

    if (!val) {
      if (dp[i + 1][0] == dp[i][1]) {
        val = 1;
      } else {
        val = 0;
      }
    } else {
      if (dp[i + 1][1] == dp[i][0]) {
        val = 0;
      } else {
        val = 1;
      }
    }
  }
  cout << s << "\n";
}

int main(){
#ifdef LOCAL
 freopen("B_input.txt", "r", stdin);
 //freopen("B_output.txt", "w", stdout);
#endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);

int t;
cin >> t;
for (int i = 0; i < t; ++i) {
  solve();
}

}