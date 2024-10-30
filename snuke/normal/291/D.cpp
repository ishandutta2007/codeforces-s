#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 10005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int x[25][MX];

int main(){
	int n, k, h, p;
	scanf("%d%d",&n,&k);
	
	rep(i,n) x[0][i] = 1;
	x[0][0] = 0;
	
	rrep(j,k){
		h = j-1;
		drep(i,n){
			p = upper_bound(x[h],x[h]+n,i-x[h][i])-x[h]-1;
			printf("%d%c",n-p,i?' ':'\n');
			x[j][i] = x[h][i]+x[h][p];
		}
	}
	
	return 0;
}