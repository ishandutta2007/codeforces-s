#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v



int main(){
	int n;
	cin >> n;
	if (n < 4) {
		puts("NO");
		return 0;
	}
	puts("YES");
	if (n&1) {
		printf("3 - 1 = 2\n");
		printf("2 + 2 = 4\n");
		printf("4 * 5 = 20\n");
		printf("20 + 4 = 24\n");
		for (int i = 6; i <= n; i+=2) {
			printf("%d - %d = 1\n",i+1,i);
			printf("24 * 1 = 24\n");
		}
	} else {
		printf("1 * 2 = 2\n");
		printf("2 * 3 = 6\n");
		printf("4 * 6 = 24\n");
		for (int i = 5; i <= n; i+=2) {
			printf("%d - %d = 1\n",i+1,i);
			printf("24 * 1 = 24\n");
		}
	}
	
	return 0;
}