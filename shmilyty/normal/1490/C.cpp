#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int t,n;
void solve()
{
	for(int i=1;i*i*i<n;i++)
	{
		int l=n-i*i*i;
		int b=floor(pow(l,1.0/3)+1e-9);
		if(b*b*b==l)
		{
			puts("Yes");
			return ;
		}
	}
	puts("No");
} 
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		solve();
	}
	return 0;
}