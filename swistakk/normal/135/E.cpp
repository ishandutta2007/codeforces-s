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
 
const int P = 1e9 + 7;
const int N = 3e6;
int fac[N];
int inv_fac[N];
int k_pow[N];
int spow(int a, int b) {
	int r = 1;
	while (b) {
		if (b % 2) {
			r = a * r % P;
		}
		a = a * a % P;
		b /= 2;
	}
	return r;
}
int Inv(int a) {
	return spow(a, P - 2);
}
int DownFac(int a, int b) {
	if (a < 0) { return 0; }
	if (b < 0) { cout<<"dupa"<<endl; }
	if (a < b) { return 0; }
	return fac[a] * inv_fac[a - b] % P;
}
int Go(int k, int w, int min_len) { // ile jest stringow dla ktorych wynik jest <=w
	// nie ma zadnego dlugosci w+1
	int max_len = k + 1 + w;
	int res = 0;
int inv_k = Inv(k);
int mid = -1;
assert(max_len - min_len <= k + 5);
	FOR (len, min_len, max_len) {
		//if (len % 10000 == 0) {
	//		cout<<len<<endl;
	//	}
		if (len >= 2 * w) {
			int c = len - 2 * w;
			int here = DownFac(k, c);
			
			int side = DownFac(k - c, w);
			int lol = here * side % P * side % P;
			debug(k, w, len, lol);
			res = (res + lol) % P;
		} else {
			int c = 2 * w - len;
			int side = DownFac(k, w - c);
if (mid == -1) { mid = spow(k, c); }
else { mid = mid * inv_k % P; }
			int lol = side * side % P * mid;
			debug(k, w, len, lol);
			res = (res + lol) % P;
		}
	}
	debug(res);
	return res;
}
int32_t main() {
 
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  int w, k;
  cin>>k>>w;
  fac[0] = 1;
  k_pow[0] = 1;
  RE (i, N - 1) {
  	fac[i] = fac[i - 1] * i % P;
  	k_pow[i] = k_pow[i - 1] * k % P;
  }
  inv_fac[N - 1] = Inv(fac[N - 1]);
  FORD (i, N - 2, 0) {
  	inv_fac[i] = inv_fac[i + 1] * (i + 1) % P;
  }
  //cout<<"hehe"<<endl;
  cout<<(Go(k, w, w) - Go(k, w - 1, w) + P) % P<<endl;
 
  return 0;
 }