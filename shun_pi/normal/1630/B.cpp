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
    REP(i, n) a[i]--;
    int th = (n+k+1) / 2;
    vector<int> cnt(n);
    REP(i, n) cnt[a[i]]++;
    int w = 1e9;
    int sum = 0;
    int i = 0;
    int j = -1;
    int x = 0;
    int y = 0;
    while(j < n) {
      if(sum >= th) {
        if(j-i < w) {
          w = j-i;
          x = i;
          y = j;
        }
        sum -= cnt[i];
        i++;
      } else {
        j++;
        sum += cnt[j];
      }
    }
    cout << x+1 << " " << y+1 << "\n";
    int kukan = 0;
    int sum1 = 0;
    int sum2 = 0;
    int l = 0;
    REP(i, n) {
      if(kukan == k - 1) {
        cout << l+1 << " " << n << "\n";
        break;
      }
      if(x <= a[i] && a[i] <= y) {
        sum1++;
      } else {
        sum2++;
      }
      if(sum1 > sum2) {
        cout << l+1 << " " << i+1 << "\n";
        kukan++;
        sum1 = 0;
        sum2 = 0;
        l = i+1;
      }
    }
  }
}