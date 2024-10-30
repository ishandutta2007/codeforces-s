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
string s[2];
int d[200010];

int main(){
    cin >> n >> k;
    rep(i, 2) cin >> s[i];
    memset(d, -1, sizeof(d));
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
	int p = q.front(); q.pop();
	int v = p / n, h = p % n;
	if(h >= n - k){
	    cout << "YES" << endl;
	    return 0;
	}
	if(h >= 1 && d[p - 1] == -1 && s[v][h - 1] == '-' && h - 1 >= d[p] + 1){
	    d[p - 1] = d[p] + 1;
	    q.push(p - 1);
	}
	if(d[p + 1] == -1 && s[v][h + 1] == '-'){
	    d[p + 1] = d[p] + 1;
	    q.push(p + 1);
	}
	int nv = n * (v ^ 1) + h + k;
	if(d[nv] == -1 && s[v ^ 1][h + k] == '-'){
	    d[nv] = d[p] + 1;
	    q.push(nv);	    
	}
    }
    cout << "NO" << endl;
    return 0;
}