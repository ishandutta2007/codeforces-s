#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,pp[8233],bb[8233],ans;
int tp[8233],tb[8233];
int p[8233],b[8233];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("? %d %d\n",0,i);
		fflush(stdout);
		scanf("%d",&pp[i]);
		printf("? %d %d\n",i,0);
		fflush(stdout);
		scanf("%d",&bb[i]);
	}
	for(int i=0;i<n;i++)
	{
		int flag=1;
		tp[0]=i;
		for(int j=0;j<n;j++)
			tb[j]=pp[j]^tp[0];
		for(int j=0;j<n;j++)
			tp[j]=bb[j]^tb[0];
		for(int j=0;j<n;j++)
		{
			if(tp[tb[j]]!=j)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			ans++;
			for(int j=0;j<n;j++)
				p[j]=tp[j];
		}
	}
	printf("!\n%d\n",ans);
	for(int i=0;i<n;i++)
	{
		printf("%d ",p[i]);
	}
	return 0;
}