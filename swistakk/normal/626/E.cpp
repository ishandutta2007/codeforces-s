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
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
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


const int N = 2e5 + 5;
int sum_pref[N];
int t[N];
LD get_cand(int l1, int r1, int l2, int r2) {
  int len = r1 - l1 + r2 - l2 + 2;
  int S = sum_pref[r1] - sum_pref[l1 - 1] + sum_pref[r2] - sum_pref[l2 - 1];
  return S * 1. / len;
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n) {
    cin>>t[i];
  }
  if (n <= 2) {
    cout<<n<<endl;
    RE (i, n) {
      cout<<t[i]<<" ";
    }
    cout<<endl;
    return 0;
  }
  sort(t + 1, t + 1 + n);
  RE (i, n) {
    sum_pref[i] = sum_pref[i - 1] + t[i];
  }
  LD best_res = -1;
  VPII ziom;
  RE (k, n) {
    int kl = 0, kp = min(n - k, k - 1);
    while (kl <= kp - 3) {
      int L = (2 * kl + kp) / 3;
      int R = (kl + 2 * kp) / 3;
      LD candL = get_cand(k - L, k, n - L + 1, n) - t[k];
      LD candR = get_cand(k - R, k, n - R + 1, n) - t[k];
      if (candL < candR) {
        kl = L + 1;
      } else {
        kp = R;
      }
    }
    FOR (i, kl, kp) {
      LD cand = get_cand(k - i, k, n - i + 1, n) - t[k];
      if (cand > best_res) {
        ziom = {{k - i, k}, {n - i + 1, n}};
        best_res = cand;
      }
    }
  }
  VI hehs;
  for (auto p : ziom) {
    FOR (i, p.st, p.nd) {
      hehs.PB(t[i]);
    }
  }
  debug(best_res);
  cout<<SZ(hehs)<<endl;
  for (auto x : hehs) {
    cout<<x<<" ";
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}