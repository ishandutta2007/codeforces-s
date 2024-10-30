// AVX-enabled std::bitset Pragmas (before #includes!)
// - bitset<200000> takes ~ 1ms per 1000 operations on GNU C++14 & GNU C++17
// #pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
// #pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
// #pragma GCC target("avx2")  //Enable AVX

// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

const int inf = 1000 << 20;
// =========== Solution ============= //

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n;
    cin >> n;
    map<string, int> namesmap;
    vector<string> names(n);
    for (string &s: names) cin >> s;
    for (int i = 0; i < n; ++i) {
      string s = names[i];
      namesmap[s] = i;
    }
    int m;
    cin >> m;
    vector<vector<bool>> mat(m, vector<bool>(n));
    vector<string> message(m);

    string _buf; getline(cin, _buf); // skip newline
    for (int i = 0; i < m; ++i) {
      string s;
      getline(cin, s);
      string word;
      bool isMessage = false;
      // tokenize
      for (char c: s) {
        if (isMessage) {
          message[i] += c;
        }
        if (c == ':') {
          if (namesmap.count(word)) {
            int k = namesmap[word];
            for (int j = 0; j < n; ++j) {
              if (j == k) continue;
              mat[i][j] = true;
            }
          }
          word = "";
          isMessage = true;
        } else if (c == '.' || c == ',' || c == ' ' || c == '!' || c == '?') {
          pp(word);
          if (namesmap.count(word)) {
            mat[i][namesmap[word]] = true;
          }
          word = "";
        } else {
          word += c;
        }
      }
      if (namesmap.count(word)) {
        mat[i][namesmap[word]] = true;
      }
    }
    pp(mat);
    pp(message);

    vector<vector<bool>> dp(m, vector<bool>(n)); // dp[i][j] -> can assign j to i, and continue from there
    for (int i = m - 1; i >= 0; --i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j]) continue;
        if (i == m - 1) dp[i][j] = true;
        else {
          for (int k = 0; k < n; ++k) {
            if (j == k) continue;
            if (dp[i + 1][k]) {
              dp[i][j] = true;
            }
          }
        }
      }
    }

    int cur = -1;
    for (int i = 0; i < n; ++i) {
      if (dp[0][i]) {
        cur = i;
        break;
      }
    }
    if (cur == -1) {
      cout << "Impossible\n";
    } else {
      for (int i = 0; i < m; ++i) {
        cout << names[cur] << ":" << message[i] << "\n";
        for (int j = 0; j < n; ++j) {
          if (i + 1 < m && cur != j && dp[i + 1][j]) {
            cur = j;
            break;
          }
        }
      }
    }
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN? different MAXN vs MAXM?)
// - special cases (n=1? graph not connected?)
// - sorting (input or ouput must be in particular order?)
// - initialize & re-initialize efficiently between test cases