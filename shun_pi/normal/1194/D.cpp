#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
int main()
{
    int T;
    cin >> T;
    while(T-->0) {
        int n, k;
        cin >> n >> k;
        if(k % 3 == 0) {
            int l = k + 1;
            if((n % l) % 3 == 0 && n % l != l-1) {
                cout << "Bob" << endl;
            } else {
                cout << "Alice" << endl;
            }
        } else {
            if(n % 3 == 0) {
                cout << "Bob" << endl;
            } else {
                cout << "Alice" << endl;
            }
        }
    }
}