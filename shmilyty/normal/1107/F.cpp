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
int n,f[501];
array<int,3> p[501];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int a=read(),b=read(),k=read();
		p[i]={-b,a,k};
	}
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++)
		for(int l=i;~l;l--)
		{
			f[l]=max(f[l],f[l]+max(0ll,p[i][1]+p[i][0]*p[i][2]));
			if(l)
				f[l]=max(f[l],f[l-1]+p[i][1]+p[i][0]*(l-1));
		}
	int ans=0;
	for(int i=1;i<=n;i++) 
		ans=max(ans,f[i]);
	cout<<ans;
	return 0;
}