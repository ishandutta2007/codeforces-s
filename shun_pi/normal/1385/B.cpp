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
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(2*n);
        REP(i, 2*n) cin >> a[i];
        vector<int> ans;
        set<int> dig;
        REP(i, 2*n) {
            if(dig.find(a[i]) == dig.end()) {
                ans.push_back(a[i]);
                dig.insert(a[i]);
            }
        }
        REP(i, n) cout << ans[i] << (i!=n-1 ? " " : "");
        cout << "\n";
    }
}