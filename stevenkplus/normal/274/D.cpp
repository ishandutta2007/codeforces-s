// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { string sep = "{"; for (auto e: v) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define pp(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// =========== Book ============ //

// =========== Solution ============= //

const int MAXN = 200100;
vector<int> edges[MAXN];
int indeg[MAXN];
vector<int> ans;

void dfs(int cur) {
  ans.push_back(cur);
  for (auto i: edges[cur]) {
    --indeg[i];
    if (indeg[i] == 0) {
      dfs(i);
    }
  }
  --indeg[cur];
}

int main() {
  int n, m;
  cin >> n >> m;

  // nodes 1...m are real nodes
  // nodes m+1... are fake nodes
  int cnt = m;
  for (int i = 0; i < n; ++i) {
    vector<pii> v(m);
    for (int j = 0; j < m; ++j) {
      cin >> v[j].fi;
      v[j].se = j + 1;
    }
    sort(v.begin(), v.end());
    int cur = -1;
    ++cnt;
    for (auto k: v) {
      if (k.fi == -1) continue;
      if (k.fi > cur) {
        cnt += 1;
        cur = k.fi;
      }
      edges[cnt - 1].push_back(k.se);
      ++indeg[k.se];
      edges[k.se].push_back(cnt);
      ++indeg[cnt];
    }
  }
  for (int i = 1; i <= cnt; ++i) {
    pp(edges[i], i);
  }

  for (int i = 1; i <= cnt; ++i) {
    if (indeg[i] == 0) dfs(i);
  }
  pp(ans);
  if (ans.size() != cnt) {
    cout << "-1\n";
  } else {
    for (auto i: ans) {
      if (i <= m) cout << i << " ";
    }
    cout << "\n";
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN? different MAXN vs MAXM?)
// - special cases (n=1? graph not connected?)
// - initialize & re-initialize efficiently between test cases
//
// history of bugs
// - 3/28/20 forgot to initialize set with dummy node (n) [cf 1136e]
// - 3/28/20 array bounds (map was size MAXN instead of MAXK) [cf 1210b]
// - 3/29/20 array bounds ([MAXN][MAXN][4] -> [MAXN][MAXN * 2][4]) [cf 1051d]
// - 3/29/20 special cases (answer cannot be empty string) [cf 848a]
// - 3/29/20 special case / bad initialization of (ans, ansi) when backtracking [cf 733f]
// - 3/30/20 special case / "0" has length 0 in binary [cf 748b]