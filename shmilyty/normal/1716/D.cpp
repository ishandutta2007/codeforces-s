#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,k,j,f[200001][2],ans[200001];
const int mod=998244353;
signed main()
{
	n=read();
	k=read();
	f[k][0]=1;
	for(int l=0;l*l<=2*n;l++,j^=1)
	{
		for(int i=0;i<=n;i++)
			f[i][j^1]=0;
		for(int i=1;i<=n;i++)
			if(i-l-k>0)
			{
				(f[i][j]+=f[i-l-k][j])%=mod;
				(f[i][j^1]+=f[i-l-k-1][j])%=mod;
			}
		for(int i=1;i<=n;i++)
			(ans[i]+=f[i][j])%=mod;
	}
	// for(int i=1;i<=n;i++)
		// (ans[i]+=f[i][j])%=mod;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}