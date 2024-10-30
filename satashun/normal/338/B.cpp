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

int n, m, d, rt, mi = -1, ans;
vector<int> g[100010];
bool ev[100010];
int di[100010];
bool inc[100010];

inline void dfs(int v, int p, int dep){
    di[v] = dep;
    rep(i, g[v].size()) if(g[v][i] != p){
	dfs(g[v][i], v, dep + 1);
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &d);
    rep(i, m){
	int t;
	scanf("%d", &t);
	ev[t - 1] = true;
	rt = t - 1;
    }
    rep(i, n - 1){
	int a, b;
	scanf("%d %d", &a, &b);
	--a; --b;
	g[a].pb(b); g[b].pb(a);
    }
    dfs(rt, -1, 0);
    rep(i, n) if(ev[i] && di[i] > mi){
	mi = di[i];
	rt = i;
    }
    dfs(rt, -1, 0);
    mi = -1;
    rep(i, n){
	if(di[i] <= d) inc[i] = true;
	if(ev[i] && mi < di[i]){
	    mi = di[i];
	    rt = i;
	}
    }
    dfs(rt, -1, 0);
    rep(i, n) if(di[i] <= d) ans += inc[i];
    cout << ans << endl;
    return 0;
}