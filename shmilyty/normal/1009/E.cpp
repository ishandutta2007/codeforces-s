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
const int mod=998244353;
int n,ans,tw[1000001];
signed main()
{
	n=read();
	tw[0]=1;
	for(int i=1;i<=n;i++)
		tw[i]=(tw[i-1]*2)%mod;
	for(int i=1;i<=n;i++)
		(ans+=(tw[n-i+1]+(n-i)*tw[n-i])%mod*read()%mod)%=mod;
	cout<<ans*499122177%mod;
	return 0;
}