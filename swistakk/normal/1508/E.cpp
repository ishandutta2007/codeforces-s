#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',') { cerr<<*sdbg++; } cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third;
  bool operator<(const Triple& t) const { if (st != t.st) return st < t.st; if (nd != t.nd) return nd < t.nd; return rd < t.rd; } };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}
typedef Triple<int, int, int> TIII;
template<class A, class B, class C>
ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.st << ", " << t.nd << ", " << t.rd << ")"; }
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

const int N = 1e6 + 5;
VI ch1[N], ch2[N];
int par[N];
int dep[N];
int a[N];
int wh[N];
int pred, postd;
int processed[N];
int pre[N];
int post[N];
void Dfs1(int v) {
  for (auto c : ch1[v]) {
    dep[c] = 1 + dep[v];
    Dfs1(c);
  }
}
void Dfs2(int v) {
  pred++;
  pre[v] = pred;
  for (auto c : ch2[v]) {
    Dfs2(c);
  }
  postd++;
  post[v] = postd;
}
int taken_sons[N];
void Up(int v) {
  if (processed[v]) { return; }
  if (v == 1) { return; }
  ch2[par[v]].PB(v);
  processed[v] = 1;
  Up(par[v]);
}
bool IsAncOf(int u, int v) {
  return pre[u] <= pre[v] && post[v] <= post[u];
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n) {
    cin>>a[i];
    wh[a[i]] = i;
  }
  RE (i, n - 1) {
    int a, b;
    cin>>a>>b;
    ch1[a].PB(b);
    par[b] = a;
  }
  Dfs1(1);
  int tm = 0;
  int breakpoint = n;
  RE (i, n) {
    int v = wh[i];
    debug(v);
    tm += dep[v];
    if (taken_sons[v] != SZ(ch1[v])) {
      debug(v);
      breakpoint = i;
      break;
    }
    taken_sons[par[v]]++;
  }
  debug(tm);
  RE (i, n) {
    int v = wh[i];
    if (processed[v]) { continue; }
    if (v == 1) { continue; }
    if (i <= breakpoint) {
      Up(v);
    } else {
      processed[v] = 1;
      ch2[par[v]].PB(v);
    }
  }
  int sum_sz = 0;
  RE (i, n) {
    sum_sz += SZ(ch2[i]);
  }
  Dfs2(1);
  debug(sum_sz);
  int fail = 0;
  RE (i, breakpoint - 1) {
    if (post[wh[i]] != i) { debug(i); fail = 1; }
  }
  int wh_post_break = -1;
  RE (i, n) {
    if (post[i] == breakpoint) { wh_post_break = i; }
  }
  if (!IsAncOf(wh[breakpoint], wh_post_break)) {
    fail = 1;
    debug(breakpoint);
  }
  FOR (i, breakpoint + 1, n - 1) {
    if (pre[wh[i]] > pre[wh[i + 1]]) { debug(i, i + 1); fail = 1; }
  }
  if (fail == 0) {
    cout<<"YES\n";
    cout<<tm<<endl;
    RE (i, n) {
      cout<<pre[i]<<" ";
    }
    cout<<endl;
  } else {
    cout<<"NO\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}