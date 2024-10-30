#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<int, int>;
using PL = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr lint B1 = 1532834020;
constexpr lint M1 = 2147482409;
constexpr lint B2 = 1388622299;
constexpr lint M2 = 2147478017;
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
template<class T>void chmax(T &a, const T &b) { if (a<b) a=b; }
template<class T>void chmin(T &a, const T &b) { if (b<a) a=b; }
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a = 1;
  vector<P> ans;
  while(true) {
    int c = 3 * a - 1;
    if(c >= n - 1) {
      int x = 1;
      int y = a - 1;
      REP(i, 2*a - 1) {
        if(y == 0) y = 2*a - 1;
        ans.push_back(P(x, y));
        x++; y--;
      }
      if(c == n-1) ans.push_back(P(n, n));
      break;
    }
    a++;
  }
  cout << ans.size() << "\n";
  REP(i, ans.size()) cout << ans[i].first << " " << ans[i].second << "\n";
}