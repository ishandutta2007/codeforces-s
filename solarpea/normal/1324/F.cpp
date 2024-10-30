//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),a[200005];
vector<int> g[200005];
int dp1[200005],dp2[200005];
inline void dfs(int x,int fa){
	if(g[x].size()==1&&g[x][0]==fa){
		dp1[x]=(a[x]==0)?-1:1;
		return;
	}
	dp1[x]=(a[x]==0)?-1:1;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y==fa)	continue;
		dfs(y,x);
		if(dp1[y]>0)	dp1[x]+=dp1[y];
	}
	dp2[x]=dp1[x];
}
inline void dfs2(int x,int fa){
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y==fa)	continue;
		int tmp1=dp1[x],tmp2=dp1[y];
		dp1[x]-=(tmp2>0)?tmp2:0;
		dp1[y]+=(dp1[x]>0)?dp1[x]:0;
		dp2[x]=max(dp2[x],dp1[x]);
		dp2[y]=max(dp2[y],dp1[y]);
		dfs2(y,x);
		dp1[x]=tmp1;dp1[y]=tmp2;
	}
}
signed main(){
	fillsmall(dp2);
	fz(i,1,n)	a[i]=read();
	fz(i,1,n-1){
		int u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);dfs2(1,0);
	fz(i,1,n)	cout<<dp2[i]<<" ";
	return 0;
}