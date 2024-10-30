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
typedef pair<int, int> P;
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

int n, k;
int ans[1000010];

int main(){
    cin >> n >> k;
    if(k * 3 > n){
	printf("-1\n");
	return 0;
    }
    /*
    int cy = n / (k * 2);
    int now = 0;
    rep(i, cy){
	rep(j, k) ans[++now] = j;
	for(int j = k - 1; j >= 0; --j) ans[++now] = j;
    }
    int r = n - cy * (k * 2);
    rep(i, min(r, k)){
	ans[++now] = i;
    }
    if(now != n){
	r -= k;
	rep(i, r) ans[++now] = k - 1 - i;
    }
    cout << now << endl;
    */
    
	int now = 0;
	rep(i, k){
	    ans[++now] = i;
	    ans[++now] = i;
	}
	rep(i, k){
	    ans[++now] = i;
	}
	while(now != n){
	    ans[++now] = 0;
	}
    
    for(int i = 1; i <= n; i++) printf("%d%c", ans[i] + 1, i == n ? '\n' : ' ');
    return 0;
}