#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define PB push_back
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debugv(x)
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
using namespace std;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
const int N = 1e5 + 5;
vector<int> nums[N];
int sieve[N];
int pres[N];
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  VPII res;
  for (int i = 2; i <= n; i++) { 
    if (sieve[i] == 0) {
      for (int j = 1; i * j <= n; j++) {
        if (sieve[i * j] == 0) {
          nums[i].PB(i * j);
          sieve[i * j] = i;
        }
      }
    }
  }
  for (int d = n; d >= 3; d--) {
    while (nums[d].size() >= 2) {
      res.PB(MP(nums[d].back(), nums[d][nums[d].size() - 2]));
      nums[d].pop_back();
      nums[d].pop_back();
    }
    if (nums[d].size()) {
      if (nums[d][0] * 2 <= n) {
        res.PB(MP(nums[d][0], 2 * nums[d][0]));
        pres[2 * nums[d][0]] = 1;
      }
    }
  }
  vector<int> rest;
  for (auto a : nums[2]) {
    if (!pres[a]) {
      rest.PB(a);
    }
  }
  while (rest.size() >= 2) {
    res.PB(MP(rest.back(), rest[rest.size() - 2]));
    rest.pop_back();
    rest.pop_back();
  }
  cout<<res.size()<<endl;
  for (auto p : res) {
    cout<<p.first<<" "<<p.second<<"\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}