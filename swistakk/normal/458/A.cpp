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
#define int long long
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debug2(x, y) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
using std::cerr;
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::set;
using std::map;
using std::pair;
using std::max;
using std::min;
using std::ostream;
using std::fixed;
using std::ios_base;
using std::setprecision;
using std::make_pair;
using std::string;
using std::multiset;
using std::next_permutation;
using std::prev_permutation;
using std::random_shuffle;
using std::greater;
using std::lower_bound;
using std::upper_bound;
using std::reverse;
using std::swap;
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
const int N = 1e6 + 5;
int dp[2][N];
const long double kEps = 1e-9;
const double phi = 1.61803398875;
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  REP (k, 2) {
    string a;
    getline(cin, a);
    for (int i = 0; i < a.length(); i++) {
      dp[k][N - 1 - i] = (int)(a[a.length() - i - 1]) - (int)('0');
    }
  }
  char c[2] = {'>', '<'};
  for (int i = 1; i <= N - 3; i++) {
    int tmp = min(dp[0][i], dp[1][i]);
    dp[0][i] -= tmp;
    dp[1][i] -= tmp;
    REP (k, 2) {
      if ((phi - 0.001) * dp[k][i] > 10 + 1.0 * (dp[k ^ 1][i + 1] - dp[k][i + 1])) {
        cout<<c[k]<<endl;
        return 0;
      }
    }
    REP (k, 2) {
      dp[k][i + 1] += dp[k][i];
      dp[k][i + 2] += dp[k][i];
    }
  }
  int equal = true;
  FOR (ind, N - 2, N - 1) {
    if (dp[0][ind] != dp[1][ind]) {
      equal = false;
    }
  }
  if (equal) {
    cout<<"="<<endl;
    return 0;
  }
  cerr<<dp[0][N - 2]<<" "<<dp[0][N - 1]<<" "<<dp[1][N - 2]<<" "<<dp[1][N - 1]<<endl;
  if (phi * dp[0][N - 2] + dp[0][N - 1] > phi * dp[1][N - 2] + dp[1][N - 1]) {
    cout<<">\n";
    return 0;
  } else {
    cerr<<"dupcia\n";
    cout<<"<\n";
    return 0;
  }
//   getline(cin, a[0]);
//   getline(cin, a[1]);
//   int diff = abs(a[0].length() - a[1].length());
//   if (a[0].length() > a[1].length()) {
//     for (int i = 0; i < diff; i++) {
//       a[1] = '0' + a[1];
//     }
//   } else {
//     for (int i = 0; i < diff; i++) {
//       a[0] = '0' + a[0];
//     }
//   }
//   cerr<<a[0]<<" "<<a[1]<<endl;
//   for (int i = 0; i < a[0].length(); i++) {
//     REP (j, 2) {
//       dp[j][i] = (int)(a[j][i]) - (int)('0');
//     }
//   }
  
//   REP (i, a[0].length() - 2) {
//     if (a[0][i] == a[1][i]) {
//       continue;
//     }
//     REP (j, 2) {
//       if (a[j][i] > a[j ^ 1][i]) {
//         if (a[j][i + 1] >= a[j ^ 1][i + 1]) {
//           if (j == 0) {
//             cout<<">\n";
//             return 0;
//           } else {
//             cout<<"<\n";
//           }
//         } else {
//           
//       }
      
  
//   REP (i, a[0].length() - 2) {
//     int mins = min(dp[0][i], dp[1][i]);
//     dp[0][i] -= mins;
//     dp[1][i] -= mins;
//     if (1.0 * dp[0][i] > 3 + 1.0 * (dp[1][i + 1] - dp[0][i + 1]) / 1.6) {
//       cout<<">\n";
//       return 0;
//     } else if (1.0 * dp[1][i] > 3 + 1.0 * (dp[0][i + 1] - dp[1][i + 1]) / 1.6) {
//       cout<<"<\n";
//       return 0;
//     }
//     dp[0][i + 1] += dp[0][i];
//     dp[0][i + 2] += dp[0][i];
//     dp[1][i + 1] += dp[1][i];
//     dp[1][i + 2] += dp[1][i];
//   }
//   int n = a[0].length();
//   if (dp[0][n - 2] == dp[1][n - 2] && dp[0][n - 1] == dp[1][n - 1]) {
//     cout<<"="<<endl;
//     return 0;
//   }
//   
//   long double x = dp[0][n - 2] - dp[1][n - 2];
//   long double y = dp[1][n - 1] - dp[0][n - 1];
//   cerr<<x<<" "<<y<<endl;
//   if (x <= kEps && y >= -kEps) {
//     cout<<"<\n";
//     return 0;
//   } else if (x >= -kEps && y <= kEps) {
//     cout<<">\n";
//     return 0;
//   }
//   int sign = 1;
//   if (x <= -kEps && y <= -kEps) {
//     x *= -1;
//     y *= -1;
//     sign *= -1;
//   }
//   if (sign * x * x > sign * (y * y - x * y)) {
//     cout<<">\n";
//   } else {
//     cerr<<"dupcia\n";
//     cout<<"<\n";
//   }
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}