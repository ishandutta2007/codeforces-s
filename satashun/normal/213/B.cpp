//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <climits>
#include <cassert>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> pii;
typedef long long ll;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define fi first
#define se second

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const ll MOD = 1000000007LL;

int n;
int a[10];
ll dp[110][10];
ll comb[110][110];
ll ret;

ll calc(int len, int i){
    if(dp[len][i] != -1) return dp[len][i];
    ll &x = dp[len][i];

    if(i == 9) return x = (len >= a[9]);
    if(i != 0){
	x = 0;
	for(int j = a[i]; j <= len; ++j){
	    x = (x + calc(len - j, i + 1) * comb[len][j]) % MOD;
	}
	return x;
    }
    x = 0;
    for(int j = a[0]; j <= len; ++j){
	x = (x + calc(len - j, 1) * comb[len - 1][j]) % MOD;
    }
    return x;
}

int main(){
    rep(i, 110) rep(j, 10) dp[i][j] = -1;
    comb[0][0] = 1;
    for(int i = 1; i <= 100; ++i){
	comb[i][0] = comb[i][i] = 1;
	for(int j = 1; j < i; ++j) comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
    }

    cin >> n;
    rep(i, 10) cin >> a[i];
    for(int i = 1; i <= n; ++i) ret = (ret + calc(i, 0)) % MOD;
    cout << ret << endl;
    return 0;
}