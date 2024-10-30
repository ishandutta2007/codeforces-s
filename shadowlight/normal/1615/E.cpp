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

vector<vector<int>> gr;
vector<int> pr;
vector<bool> is_leaf;
vector<bool> marked;
vector<int> tin, tout;
vector<int> values;
vector<int> num;

int timer = 0;

void dfs(int v, int p, int h = 1) {
  pr[v] = p;
  for (int u : gr[v]) {
    if (u == p) continue;
    dfs(u, v, h + 1);
    if (tin[v] == -1) {
      tin[v] = tin[u];
    }
    tout[v] = tout[u];
  }

  if (gr[v].size() == 1 && p != -1) {
    tin[v] = timer++;
    tout[v] = timer;
    num.pb(v);
    values.pb(h);
  }
}

struct Tree {
  int n;
  vector<pair<int, int>> t;
  vector<int> val;

  void relax(int v) {
    t[v] = max(t[2 * v], t[2 * v + 1]);
  }

  void add_val(int v, int valt) {
    t[v].x += valt;
    val[v] += valt;
  }

  void push(int v) {
    add_val(2 * v, val[v]);
    add_val(2 * v + 1, val[v]);
    val[v] = 0;
  }

  void build_tree(int v, int l, int r, vector<int> &values) {
    if (r - l == 1) {
      t[v] = {values[l], l};
      return;
    }
    int m = (l + r) / 2;
    build_tree(2 * v, l, m, values);
    build_tree(2 * v + 1, m, r, values);
    relax(v);
  }

  Tree(vector<int> &values) : n(values.size()), t(4 * n), val(4 * n, 0) {
    build_tree(1, 0, n, values);
  }

  void add_seg(int l, int r, int x, int vt, int lt, int rt) {
    if (l >= rt || lt >= r) {
      return;
    }
    if (l <= lt && rt <= r) {
      add_val(vt, x);
      return;
    }
    int mt = (lt + rt) / 2;
    push(vt);
    add_seg(l, r, x, 2 * vt, lt, mt);
    add_seg(l, r, x, 2 * vt + 1, mt, rt);
    relax(vt);
  }

  void add_seg(int l, int r, int x) {
    add_seg(l, r, x, 1, 0, n);
  }
};

int blue = 0;

bool blue_dfs(int v, int p) {
  bool can = !marked[v];
  for (int u : gr[v]) {
    if (u == p) continue;
    can &= blue_dfs(u, v);
  }
  blue += can;
  return can;
}

const ll LINF = 1e18;

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, k;
  cin >> n >> k;
  gr.resize(n);
  is_leaf.resize(n, false);
  tin.resize(n, -1);
  tout.resize(n, -1);
  pr.resize(n, -1);

  for (int i = 1; i < n; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    gr[v].pb(u);
    gr[u].pb(v);
  }

  int leaves = 0;
  for (int i = 1; i < n; ++i) {
    if (gr[i].size() == 1) {
      is_leaf[i] = true;
      ++leaves;
    }
  }

  if (leaves <= k) {
    ll res = 0;
    for (int x = leaves; x <= k; ++x) {
      uax(res, x * (ll) (n - x));
    }
    cout << res << "\n";
    return 0;
  }

  dfs(0, -1);
  marked.resize(n, false);

  Tree tree(values);
  assert((int)values.size() == leaves);

  for (int i = 0; i < k; ++i) {
    auto t = tree.t[1];
    int v = num[t.y];

    assert(!marked[v]);
    while (v != -1 && !marked[v]) {
      marked[v] = true;
      tree.add_seg(tin[v], tout[v], -1);
      v = pr[v];
    }
  }
  blue_dfs(0, -1);
  ll res = LINF;
  for (int b = 0; b <= blue; ++b) {
    uin(res, (k - b) * (ll) (n - k - b));
  }
  cout << res << "\n";
}