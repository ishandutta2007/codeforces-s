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
const int N = 1e3 + 5;
ll dp[N][N][4];
ll a[N][N];
int dx[4] = {1, -1, 1, -1};
int dy[4] = {1, -1, -1, 1};
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make2(int, n, m);
  RE (i, n) {
    RE (j, m) {
      cin>>a[i][j];
    }
  }
  for (int dir = 0; dir <= 3; dir++) {
    int st_i, st_j;
    if (dir == 0 || dir == 3) {
      st_i = 1;
    } else {
      st_i = n;
    }
    if (dir == 0 || dir == 2) {
      st_j = 1;
    } else {
      st_j = m;
    }
    for (int i = st_i; i >= 1 && i <= n; i += dy[dir]) {
      for (int j = st_j; j >= 1 && j <= m; j += dx[dir]) {
        dp[i][j][dir] = a[i][j] + max(dp[i - dy[dir]][j][dir], dp[i][j - dx[dir]][dir]);
      }
    }
  }
  ll best = 0;
  FOR (i, 2, n - 1) {
    FOR (j, 2, m - 1) {
      maxi(best, max(dp[i - 1][j][0] + dp[i + 1][j][1] + dp[i][j - 1][2] + dp[i][j + 1][3],
          dp[i - 1][j][3] + dp[i + 1][j][2] + dp[i][j - 1][0] + dp[i][j + 1][1]));
    }
  }
  cout<<best<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}