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
#include<iostream>
#include<sstream>
#include<cctype>
#include<sys/time.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
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

const int MX = 500005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int a[MX];
int nx[MX], pr[MX];
P p[MX];

int main(){
	int n;
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) p[i] = P(a[i],i);
	sort(p,p+n);
	rep(i,n) nx[i] = i+1;
	rep(i,n) pr[i] = i-1;
	int l = 0, r = n-1;
	ll ans = 0;
	rep(pi,n-2){
		int i = p[pi].se;
		if(i == l){
			ans += a[i];
			l = nx[l];
		} else if(i == r){
			ans += a[i];
			r = pr[i];
		} else {
			ans += min(a[pr[i]], a[nx[i]]);
			pr[nx[i]] = pr[i]; 
			nx[pr[i]] = nx[i]; 
		}
	}
	cout << ans << endl;
	
	return 0;
}