#include<stdio.h>
main()
{
	long int a,b,c,t,i,j,k,temp,data[3],cnt,flag;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld%ld",&data[0],&data[1],&data[2]);
		for(i=0;i<2;i++)
		{
			for(k=0;k<2-i;k++)
			{
				if(data[k]<data[k+1])
				{
					temp=data[k];
					data[k]=data[k+1];
					data[k+1]=temp;
				}
			}
		}
		a=data[0];
		b=data[1];
		c=data[2];
		if((a+b+c)%9)
		{
			printf("no\n");
			continue;
		}
		temp=(a-b)/6;
		a-=temp*7;
		b-=temp;
		c-=temp;
		temp=(b-c)/3;
		a-=temp*4;
		b-=temp*4;
		c-=temp;
		if(c<0)
		{
			printf("no\n");
			continue;
		}
		temp=c/3;
		a-=temp;
		b-=temp;
		c-=temp;
		if(a==0)
		{
			if(b==0&&c==0)printf("yes\n");
			else printf("no\n");
		}
		else printf("yes\n");
		/*cnt=0;
		flag=1;
		while(flag)
		{
			if(cnt!=6)
			{
				if(a>b)a--;
				else
				{
					if(b>c)b--;
					else c--;
				}
				cnt++;
			}
			else
			{
				a--;
				b--;
				c--;
				cnt=0;
			}
			if(c<0)
			{
				printf("no\n");
				flag=0;
			}
			if(a==0&&b==0&&c==0)
			{
				printf("yes\n");
				flag=0;
			}
		}*/
	}
}