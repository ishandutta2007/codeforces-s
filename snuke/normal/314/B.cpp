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

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

char ins[105], ins2[105];
string s, t;
int l[105];

int main(){
	int b, d, n, m, p;
	scanf("%d%d%s%s",&b,&d,ins,ins2);
	s = ins, t = ins2; n = s.size(); m = t.size();
	rep(i,m){
		p = i; l[i] = 0;
		rep(j,n){
			if(s[j] == t[p]){
				p = (p+1)%m;
				l[i]++;
			}
		}
	}
	
	int c = 0; p = 0;
	rep(i,b){
		c += l[p];
		p = (p+l[p])%m;
	}
	
	printf("%d\n",c/m/d);
	
	return 0;
}