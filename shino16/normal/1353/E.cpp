#line 2 "C:/Users/W/c/lib/template.cpp"

#ifndef LOCAL
#pragma GCC diagnostic warning "-w"
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#endif
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VLL = vector<ll>;
using VVLL = vector<vector<ll>>;
using VB = vector<bool>;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
constexpr int INF = 1000000007;
constexpr ll INF_LL = 1'000'000'000'000'000'007;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define newl '\n'

// loops rep(until) / rep(var, until) / rep(var, from, until) / repr (reversed order)
#define OVERLOAD3(_1, _2, _3, name, ...) name
#define rep(...) OVERLOAD3(__VA_ARGS__, REPEAT_FROM_UNTIL, REPEAT_UNTIL, REPEAT)(__VA_ARGS__)
#define REPEAT(times) REPEAT_CNT(_repeat, __COUNTER__, times)
#define REPEAT_CNT(_repeat, cnt, times) REPEAT_CNT_CAT(_repeat, cnt, times)
#define REPEAT_CNT_CAT(_repeat, cnt, times) REPEAT_FROM_UNTIL(_repeat ## cnt, 0, times)
#define REPEAT_UNTIL(name, times) REPEAT_FROM_UNTIL(name, 0, times)
#define REPEAT_FROM_UNTIL(name, from, until) for (int name = from, name ## __until = (until); name < name ## __until; name++)
#define repr(...) OVERLOAD3(__VA_ARGS__, REPR_FROM_UNTIL, REPR_UNTIL, REPEAT)(__VA_ARGS__)
#define REPR_UNTIL(name, times) REPR_FROM_UNTIL(name, 0, times)
#define REPR_FROM_UNTIL(name, from, until) for (int name = (until)-1, name ## __from = (from); name >= name ## __from; name--)

template <typename T, typename U>
bool chmin(T& var, U x) { if (var > x) { var = x; return true; } else return false; }
template <typename T, typename U>
bool chmax(T& var, U x) { if (var < x) { var = x; return true; } else return false; }
ll power(ll e, ll t, ll mod = INF_LL) {
  ll res = 1; for (; t; t >>= 1, (e *= e) %= mod) if (t & 1) (res *= e) %= mod; return res;
}
ll choose(ll n, int r) {
  chmin(r, n-r); if (r < 0) return 0; ll res = 1; rep(i, r) res *= n-i, res /= i+1; return res;
}
template <typename T> T divceil(T m, T d) { return (m + d - 1) / d; }
template <typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

// debug stuff
#define repi(it, ds) for (auto it = ds.begin(); it != ds.end(); it++)
class DebugPrint { public: template <typename T> DebugPrint& operator <<(const T& v) {
#ifdef LOCAL
    cerr << v;
#endif
return *this; } } debugos; template <typename T> DebugPrint& operator<<(DebugPrint& os, const
vector<T>& vec) { os << "{"; for (int i = 0; i < vec.size(); i++) os << vec[i] << (i + 1 ==
vec.size() ? "" : ", "); os << "}"; return os; } template <typename T, typename U> DebugPrint&
operator<<(DebugPrint& os, map<T, U>& map_var) { os << "{"; repi(itr, map_var) { os << *itr;
itr++; if (itr != map_var.end()) os << ", "; itr--; } os << "}"; return os; } template <
typename T> DebugPrint& operator<<(DebugPrint& os, set<T>& set_var) { os << "{"; repi(itr,
set_var) { os << *itr; itr++; if (itr != set_var.end()) os << ", "; itr--; } os << "}"; return
os; } template <typename T, typename U> DebugPrint& operator<<(DebugPrint& os, const pair<T, U
>& p) { os << "(" << p.first << ", " << p.second << ")"; return os; } void dump_func() {
debugos << newl; } template <class Head, class... Tail> void dump_func(Head &&head, Tail &&...
tail) { debugos << head; if (sizeof...(Tail) > 0) { debugos << ", "; } dump_func(std::move(
tail)...); }
#define dump(...) debugos << "  " << string(#__VA_ARGS__) << ": " << "[" << to_string(__LINE__) \
<< ":" << __FUNCTION__ << "]" << newl << "    ", dump_func(__VA_ARGS__)
#pragma GCC diagnostic pop


#line 2 "C:/Users/W/c/lib/data-structure/disjoint-sparse-table.cpp"

#line 2 "C:/Users/W/c/lib/util/function-objects.cpp"

#line 4 "C:/Users/W/c/lib/util/function-objects.cpp"

struct minT {
  template <typename T>
  T operator()(T a, T b) const {
    return min(a, b);
  }
};

struct maxT {
  template <typename T>
  T operator()(T a, T b) const {
    return max(a, b);
  }
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct assignT {
  template <typename T>
  T operator()(T a, T b, int k = 0) const { return b; }
};
#pragma GCC diagnostic pop

struct plusT {
  template <typename T>
  T operator()(T a, T b, int k) const { return a + b * k; }
};
#line 5 "C:/Users/W/c/lib/data-structure/disjoint-sparse-table.cpp"

template <typename T, typename F>
class DisjointSparseTable {
 private:
  const int n, h;
  vector<vector<T>> table;
  const F f;

 public:
  DisjointSparseTable() {}
  template <typename Iter>
  DisjointSparseTable(Iter first, Iter last, F _f = F())
      : n(distance(first, last)),
        h(32 - __builtin_clz(n)),
        table(h, vector<T>(n)),
        f(_f) {
    move(first, last, table[0].begin());
    rep(s, 1, h) rep(k, (n + (1 << (s + 1)) - 1) >> (s + 1)) {
      int l = k << (s + 1);
      int m = min(n, l + (1 << s));
      int r = min(n, m + (1 << s));
      table[s][m - 1] = table[0][m - 1];
      repr(i, l, m - 1) table[s][i] = f(table[0][i], table[s][i + 1]);
      if (m != n) {
        table[s][m] = table[0][m];
        rep(i, m + 1, r) table[s][i] = f(table[s][i - 1], table[0][i]);
      }
    }
  }

 public:
  T fold(int l, int r) {
    r--;
    if (l > r) return 0;
    if (l == r) return table[0][l];
    int s = 32 - __builtin_clz(l ^ r) - 1;
    return f(table[s][l], table[s][r]);
  }
};

#ifdef 	__cpp_deduction_guides
template <typename Iter, typename F>
DisjointSparseTable(Iter first, Iter last, F _f = F())
    -> DisjointSparseTable<typename Iter::value_type, F>;
#endif
#line 3 "e.cpp"

int main() {
	cin.tie(0);	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	rep(t) {
		int n, k; cin >> n >> k;
		string s_; cin >> s_;
		VI s(n); rep(i, n) s[i] = s_[i] - '0';

		auto dp = make_v(3, k, divceil(n, k) + 1, INF);
		DisjointSparseTable dst(all(s), plus<>());
		rep(i, k) dp[0][i][0] = dst.fold(0, i+1), dp[1][i][0] = dst.fold(0, i) + !s[i];

		rep(i, k, n) {
			dp[0][i%k][i/k] = dp[0][i%k][i/k-1] + dst.fold(max(0, i-k+1), i+1);
			chmin(dp[1][i%k][i/k],
						min(dp[1][i%k][i/k-1], dp[0][i%k][i/k-1]) + dst.fold(max(0, i-k+1), i) + !s[i]);
			chmin(dp[2][i%k][i/k],
						min(dp[1][i%k][i/k-1], dp[2][i%k][i/k-1]) + dst.fold(max(0, i-k+1), i+1));
		}

		int res = INF;
		rep(i, 3) rep(j, n-k, n) chmin(res, dp[i][j%k][j/k] + dst.fold(j+1, n));
		cout << res << newl;
	}
}