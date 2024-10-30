#include <bits/stdc++.h>

#define __INIT_CC__ ios::sync_with_stdio(false); \
	cin.tie(0);

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define FORLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORNLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)<=(_t);++(_i))
#define FORDLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)>=(_t);--(_i))
#define FOREACH(_i,_a) for (__typeof(_a.begin()) _i=_a.begin();_i!=_a.end();++_i)
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define SIZE(_a) (int)_a.size()
#define VSORT(_a) sort(_a.begin(),_a.end())
#define SSORT(_a,_val) sort(_a,_a+(_val))
#define ALL(_a) _a.begin(),_a.end()
#define mt make_tuple
#define _get(_tuple,_i) get<_i>(_tuple)
#define eb emplace_back
 
using namespace std;
 
const int dr[] = { 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[] = { 0, 1, 0,-1, 1,-1,-1, 1};
const double eps = 1e-9;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef pair<double,double> pdd;
typedef vector<pdd> vpdd;
const int INF = 0x7FFFFFFF;
const ll INFLL = 0x7FFFFFFFFFFFFFFFLL;
const double pi = acos(-1);

template <class T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <class T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> inline void getint(T &num)
{
	bool neg = 0;
	num = 0;
	char c;
	while ((c = getchar_unlocked()) && (!isdigit(c) && c != '-'));
	if (c == '-')
	{
		neg = 1;
		c = getchar_unlocked();
	}
	do num = num * 10 + c - '0';
	while ((c = getchar_unlocked()) && isdigit(c));
	if (neg) num = -num;
}

template <class T> inline bool inRange(T z, T a, T b){return a <= z && z <= b;}

void OPEN(string in = "input.txt",string out = "output.txt")
{
	freopen(in.c_str(), "r", stdin);
	freopen(out.c_str(), "w", stdout);
	return ;
}

//using sokokaleb's template v3.1

#define N 1005
string arr[N];
int r, c;
int nr[N][N];

void ok() {
	cout << "YES\n";
	exit(0);
}

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> r >> c;
	FOR (i, 0, r) {
		cin >> arr[i];
	}

	FOR (i, 0, r) {
		FOR (j, 0, c) {
			if (arr[i][j] == 'T') {
				FOR (k, 0, 4) {
					int ni = i, nj = j;
					while (inRange(ni, 0, r - 1) && inRange(nj, 0, c - 1) && arr[ni][nj] != '*') {
						nr[ni][nj] |= 1;
						ni += dr[k];
						nj += dc[k];
					}
				}
			}
		}
	}

	FOR (i, 0, r) {
		FOR (j, 0, c) {
			if (arr[i][j] == 'S') {
				FOR (k, 0, 4) {
					int ni = i, nj = j;
					while (inRange(ni, 0, r - 1) && inRange(nj, 0, c - 1) && arr[ni][nj] != '*') {
						nr[ni][nj] |= 2;
						ni += dr[k];
						nj += dc[k];
					}
				}
			}
		}
	}

	FOR (i, 0, r) {
		int lol = 0;
		FOR (j, 0, c) {
			if (arr[i][j] == '*') lol = 0;
			else lol |= nr[i][j];
			if (lol == 3) ok();
		}
		lol = 0;
		FORD (j, c - 1, 0) {
			if (arr[i][j] == '*') lol = 0;
			else lol |= nr[i][j];
			if (lol == 3) ok();
		}
	}
	FOR (j, 0, c) {
		int lol = 0;
		FOR (i, 0, r) {
			if (arr[i][j] == '*') lol = 0;
			else lol |= nr[i][j];
			if (lol == 3) ok();
		}
		lol = 0;
		FORD (i, r - 1, 0) {
			if (arr[i][j] == '*') lol = 0;
			else lol |= nr[i][j];
			if (lol == 3) ok();
		}
	}
	cout << "NO\n";
	return 0;
}