#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
int t,n,a[200001],b[200001],na[200001],nb[200001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		na[i]=nb[i]=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=read();
		na[a[i]]++;
		nb[b[i]]++;
	}
	int ans=n*(n-1)/2*(n-2)/3;
	for(int i=1;i<=n;i++)
		ans-=(na[a[i]]-1)*(nb[b[i]]-1);
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}