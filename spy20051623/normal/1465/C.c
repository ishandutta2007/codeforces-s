#include<stdio.h>
main()
{
	long int s[100005],n,m,i,j,k,x,y;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<100005;i++)s[i]=-1;
		scanf("%ld%ld",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%ld",&j);
			scanf("%ld",&s[j]);
		}
		k=m;
		for(j=0;j<=n;j++)
		{
			if(s[j]==j)
			{
				s[j]=-1;
				k--;
			}
			else if(s[j]!=-1)
			{
				x=j;
				do
				{
					x=s[x];
				}
				while(x!=-1&&x!=j);
				if(x==j)
				{
					k++;
				}
				x=y=j;
				while(s[x]!=-1)
				{
					x=s[x];
					s[y]=-1;
					y=x;
				}
				s[x]=-1;
			}
		}
		printf("%ld\n",k);
	}
}