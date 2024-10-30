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
template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

// ============= Solution ============= //
int main() {
   int T;
   cin >> T;
   for (int t = 1; t <= T; ++t) {
      int n, a, b, da, db;
      cin >> n >> a >> b >> da >> db;
      --a, --b;
      vector<vector<int>> ed(n);
      for (int i = 0; i < n - 1; ++i) {
         int u, v;
         cin >> u >> v;
         --u, --v;
         ed[u].push_back(v);
         ed[v].push_back(u);
      }
      auto dfs = yc([&](auto dfs, int cur, int prv, vector<int> &dists) -> void {
         for (int nxt: ed[cur]) {
            if (nxt == prv) continue;
            dists[nxt] = dists[cur] + 1;
            dfs(nxt, cur, dists);
         }
      });
      auto get_diam = [&]() -> int {
         vector<int> d1(n), d2(n);
         dfs(0, -1, d1);
         int rt = 0;
         for (int i = 0; i < n; ++i) {
            if (d1[i] > d1[rt]) rt = i;
         }
         dfs(rt, -1, d2);
         return *max_element(d2.begin(), d2.end());
      };
      vector<int> dista(n);
      dfs(a, -1, dista);
      int diam = get_diam();
      pp(da, db, diam);
      if (dista[b] <= da || 2 * da >= min(db, diam)) {
         cout << "Alice\n";
      } else {
         cout << "Bob\n";
      }
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases