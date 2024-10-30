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

vector<int> pre_kmp(string pat){
    int k;
    vector<int> table((int)pat.size() + 1);
    table[0] = -1;

    for(int i = 1; i <= pat.size(); ++i){
	k = table[i-1];

	while(k >= 0){
	    if(pat[k] == pat[i-1]) break;
	    else k = table[k];
	}

	table[i] = k + 1;
    }

    return table;
}

int n;
string s;
vector<int> vec;

int main(){
    cin >> s;
    n = s.size();
    vec = pre_kmp(s);
 //   for(int x : vec) cout << x << endl;

    if(vec[n] == 0){
	cout << "Just a legend\n";
	return 0;
    }

    rep(i, n) if(vec[i] == vec[n]){
	rep(j, vec[n]) cout << s[j];
	cout << "\n";
	return 0;
    }

    if(vec[vec[n]] == 0){
	cout << "Just a legend\n";
	return 0;	
    }

    rep(i, vec[vec[n]]) cout << s[i];
    cout << "\n";

    return 0;
}