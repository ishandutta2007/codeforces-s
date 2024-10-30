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
  int T;
  cin >> T;
  while(T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    multiset<int, greater<int>> st;
    REP(i, n) st.insert(a[i]);
    int now = 0;
    int rest = k;
    while(true) {
      if(st.find(now) == st.end()) {
        if(rest == 0) break;
        rest--;
      }
      now++;
    }
    map<int, int> mp;
    REP(i, n) if(a[i] > now) mp[a[i]]++;
    multiset<int> cnt;
    for (auto const& [key, val] : mp) cnt.insert(val);
    while(!cnt.empty()) {
      int x = *cnt.begin();
      if(x > k) break;
      cnt.erase(cnt.begin());
      k -= x;
    }
    cout << cnt.size() << "\n";
  }
}