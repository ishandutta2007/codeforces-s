#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    REP(t, T) {
        int n, x;
        cin >> n >> x;
        int cnt = 0;
        REP(i, n-1) {
            int u, v;
            cin >> u >> v;
            if(u == x || v == x) cnt++;
        }
        if(cnt <= 1) {
            cout << "Ayush" << "\n";
        } else if((n-1)%2 == 0) {
            cout << "Ashish" << "\n";
        } else {
            cout << "Ayush" << "\n";
        }
    }
}