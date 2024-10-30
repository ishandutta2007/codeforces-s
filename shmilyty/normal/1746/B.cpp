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
int T,n,a[100010];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		while(!a[l])
			l++;
		while(a[r])
			r--;
		if(l>r)
			break;
		ans++;
		l++;
		r--;
	}
	cout<<ans<<'\n';
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}