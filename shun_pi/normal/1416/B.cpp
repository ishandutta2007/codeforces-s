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
struct S{int i, j, x;};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    int sum = 0;
    REP(i, n) sum += a[i];
    if(sum%n != 0) {
      cout << -1 << "\n";
      continue;
    }
    int target = sum / n;
    vector<S> ans;
    FOR(i, 1, n) {
      int tmp = (a[0] + a[i])/(i+1)*(i+1);
      ans.push_back(S{1, i+1, tmp-a[i]});
      ans.push_back(S{i+1, 1, (tmp)/(i+1)});
      a[0] += a[i];
      a[i] = 0;
    }
    FOR(i, 1, n) {
      ans.push_back(S{1, i+1, target});
    }
    cout << ans.size() << "\n";
    REP(i, ans.size()) {
      cout << ans[i].i << " " << ans[i].j << " " << ans[i].x << "\n";
    }
  }
}