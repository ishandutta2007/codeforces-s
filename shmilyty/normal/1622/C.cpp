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
int t,n,k,ans,a[200001];
void solve()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	ans=INF;
	for(int i=n;i;i--)
	{
		int cnt=n-i+1;
		ans=min(ans,cnt-1+max(0ll,(a[i]+(cnt-1)*a[1]+cnt-1-k)/cnt));
	}
	cout<<max(ans,0ll)<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}