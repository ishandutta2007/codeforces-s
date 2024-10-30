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

const int N = 1e3 + 5;
VI slo[N];
int sz[N];
void Dfs(int v) {
  sz[v] = 1;
  for (auto nei : slo[v]) {
    if (sz[nei]) { continue; }
    Dfs(nei);
    sz[v] += sz[nei];
  }
}
int in_small_part[N];
VVI ans;
int in_part;
int vall[N];
void Numeruj(int v, int par, int step) {
  in_part += step;
  for (auto nei : slo[v]) {
    if (nei == par) { continue; }
    vall[nei] = in_part;
    ans.PB({v, nei, vall[nei] - vall[v]});
    Numeruj(nei, v, step);
  }
}
int val[N][N];
int is[N * N];
void Check(int v, int par, int acc) {
  is[acc] = 1;
  for (auto nei : slo[v]) {
    if (nei == par) { continue; }
    assert(val[v][nei]);
    Check(nei, v, acc + val[v][nei]);
  }
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n - 1) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    slo[b].PB(a);
  }
  int cent = -1;
  RE (i, n) {
    RE (j, n) {
      sz[j] = 0;
    }
    Dfs(i);
    int fail = 0;
    for (auto nei : slo[i]) {
      if (2 * sz[nei] > n) { fail = 1; break; }
    }
    if (fail) { continue; }
    cent = i;
    break;
  }
  debug(cent);
  VPII subs;
  for (auto son : slo[cent]) {
    subs.PB({sz[son], son});
  }
  sort(ALL(subs));
  in_part = 1;
  for (auto sub : subs) {
    //if (in_small_part[sub.nd] == 0) { continue; }
    ans.PB({cent, sub.nd, in_part});
    vall[sub.nd] = in_part;
    Numeruj(sub.nd, cent, 1);
    //in_left += sub.st;
    in_small_part[sub.nd] = 1;
    if (3 * (in_part - 1) >= n - 1) { break; }
  }
  assert(in_part * (n - in_part + 1) >= (2 * n * n / 9));
  int step = in_part;
  in_part = step;
  for (auto sub : subs) {
    if (in_small_part[sub.nd]) { continue; }
    ans.PB({cent, sub.nd, in_part});
    vall[sub.nd] = in_part;
    Numeruj(sub.nd, cent, step);
  }
  assert(SZ(ans) == n - 1);
  for (auto e : ans) {
    cout<<e[0]<<" "<<e[1]<<" "<<e[2]<<endl;
//#ifdef LOCAL
    val[e[0]][e[1]] = e[2];
    val[e[1]][e[0]] = e[2];
//#endif
  }
  fflush(stdout);
//#ifdef LOCAL
  RE (i, n) {
    Check(i, -1, 0);
  }
  RE (i, 2 * n * n / 9) {
    assert(is[i]);
  }
//#endif
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}