#pragma GCC optimize ("Ofast")//1
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
int t,n,a,sum;
void solve()
{
	n=read();
	sum=0ll;
	bool flag=0;
	for(int i=0;i<n;i++)
	{
		a=read();
		if(a+sum>=i)
			sum=a+sum-i;
		else
			flag=1;
	}
	if(flag)
		puts("No");
	else
		puts("Yes");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}