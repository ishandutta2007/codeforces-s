#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
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
        string s;
        cin >> s;
        bool flg = true;
        REP(i, s.size()) {
            if(s[0] != s[i]) {
                flg = false;
                break;
            }
        }
        if(flg) {
            cout << s << "\n";
        } else {
            REP(i, s.size()) {
                cout << "01";
            }
            cout << "\n";
        }
    }
}