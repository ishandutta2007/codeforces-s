#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
int main()
{
    int T;
    cin >> T;
    REP(t, T) {
        string a, b, c;
        cin >> a >> b >> c;
        bool flg = true;
        REP(i, a.size()) {
            if(a[i] != c[i] && b[i] != c[i]) {
                flg = false;
                break;
            }
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    
}