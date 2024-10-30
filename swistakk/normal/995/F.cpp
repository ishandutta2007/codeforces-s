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
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
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

const int N = 3e3 + 5;
//int dp[N][N];
int E[N][N];
int F[N][N];
VI slo[N];
const int P = 1e9 + 7;
void Dfs(int v) {
//   if (slo[v].empty()) {
//     RE (k, N - 1) {
//       E[v][k] = 1;
//       F[v][k] = k;
//     }
//     return;
//   }
  RE (k, N - 1) {
    E[v][k] = 1;
  }
  for (auto son : slo[v]) {
    Dfs(son);
    RE (k, N - 1) {
      E[v][k] = E[v][k] * F[son][k] % P;
    }
  }
  RE (k, N - 1) {
    F[v][k] = (F[v][k - 1] + E[v][k]) % P;
  }
}
int spow(int a, int b, int p) {
  int r = 1;
  while (b) {
    if (b % 2) {
      r = r * a % p;
    }
    a = a * a % p;
    b /= 2;
  }
  return r;
}
int Mod(int x) {
  x = x % P;
  if (x < 0) {
    return x + P;
  }
  return x;
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, D;
  cin>>n>>D;
  FOR (i, 2, n) {
    int p;
    cin>>p;
    slo[p].PB(i);
  }
  Dfs(1);
  //cout<<F[1][D]<<endl;

  
  int res = 0;
  RE (k, n + 1) {
    int num = 1, den = 1;
    RE (j, n + 1) {
      if (k == j) { continue; }
      num = Mod(num * (D - j) % P);
      den = Mod(den * (k - j) % P);
    }
    res = Mod(res + num * spow(den, P - 2, P) % P * F[1][k]);
  }
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}