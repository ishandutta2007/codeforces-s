#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			flag=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
    return (flag?x:~(x-1));
}
int t,a,b;
signed main()
{
	t=read();
	while(t--)
	{
		a=read();
		b=read();
		if(a==b)
		{
			cout<<a*2<<endl;
			continue;	
		}	
		int rest=max(a,b)-min(a,b)-1;
		cout<<2*min(a,b)+1+2*rest<<endl;
	} 
	return 0;
}