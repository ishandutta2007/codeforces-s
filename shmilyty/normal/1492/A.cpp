#pragma GCC optimize ("Ofast")
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
int t,x,a,b,c;
signed main()
{
	t=read();
	while(t--)
	{
		cin>>x>>a>>b>>c;
		cout<<min((a-x%a)%a,min((b-x%b)%b,(c-x%c)%c))<<endl;	
	} 
	return 0;
}