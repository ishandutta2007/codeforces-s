#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int main()
{
	int k;scanf("%d",&k);k=34-k;
	if(k==0)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.O.O.O.O.|D|)\n");
		printf("|O.O.O.O.O.O.O.O.O.O.O.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.O.O.O.O.O.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==1)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.O.O.O.O.|D|)\n");
		printf("|O.O.O.O.O.O.O.O.O.O.O.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.O.O.O.O.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==2)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.O.O.O.O.|D|)\n");
		printf("|O.O.O.O.O.O.O.O.O.O.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.O.O.O.O.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==3)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.O.O.O.#.|D|)\n");
		printf("|O.O.O.O.O.O.O.O.O.O.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.O.O.O.O.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==4)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.O.O.O.#.|D|)\n");
		printf("|O.O.O.O.O.O.O.O.O.O.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.O.O.O.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==5)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.O.O.O.#.|D|)\n");
		printf("|O.O.O.O.O.O.O.O.O.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.O.O.O.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==6)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.O.O.#.#.|D|)\n");
		printf("|O.O.O.O.O.O.O.O.O.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.O.O.O.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==7)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.O.O.#.#.|D|)\n");
		printf("|O.O.O.O.O.O.O.O.O.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.O.O.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==8)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.O.O.#.#.|D|)\n");
		printf("|O.O.O.O.O.O.O.O.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.O.O.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==9)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.O.#.#.#.|D|)\n");
		printf("|O.O.O.O.O.O.O.O.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.O.O.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==10)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.O.#.#.#.|D|)\n");
		printf("|O.O.O.O.O.O.O.O.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.O.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==11)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.O.#.#.#.|D|)\n");
		printf("|O.O.O.O.O.O.O.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.O.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==12)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.#.#.#.#.|D|)\n");
		printf("|O.O.O.O.O.O.O.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.O.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==13)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.#.#.#.#.|D|)\n");
		printf("|O.O.O.O.O.O.O.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==14)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.O.#.#.#.#.|D|)\n");
		printf("|O.O.O.O.O.O.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==15)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.#.#.#.#.#.|D|)\n");
		printf("|O.O.O.O.O.O.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.O.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==16)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.#.#.#.#.#.|D|)\n");
		printf("|O.O.O.O.O.O.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==17)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.O.#.#.#.#.#.|D|)\n");
		printf("|O.O.O.O.O.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==18)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.#.#.#.#.#.#.|D|)\n");
		printf("|O.O.O.O.O.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.O.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==19)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.#.#.#.#.#.#.|D|)\n");
		printf("|O.O.O.O.O.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==20)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.O.#.#.#.#.#.#.|D|)\n");
		printf("|O.O.O.O.#.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==21)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.#.#.#.#.#.#.#.|D|)\n");
		printf("|O.O.O.O.#.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.O.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==22)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.#.#.#.#.#.#.#.|D|)\n");
		printf("|O.O.O.O.#.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==23)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.O.#.#.#.#.#.#.#.|D|)\n");
		printf("|O.O.O.#.#.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==24)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.#.#.#.#.#.#.#.#.|D|)\n");
		printf("|O.O.O.#.#.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.O.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==25)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.#.#.#.#.#.#.#.#.|D|)\n");
		printf("|O.O.O.#.#.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.#.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}if(k==26)
	{
		printf("+------------------------+\n");
		printf("|O.O.O.#.#.#.#.#.#.#.#.|D|)\n");
		printf("|O.O.#.#.#.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.#.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==27)
	{
		printf("+------------------------+\n");
		printf("|O.O.#.#.#.#.#.#.#.#.#.|D|)\n");
		printf("|O.O.#.#.#.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.O.#.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}if(k==28)
	{
		printf("+------------------------+\n");
		printf("|O.O.#.#.#.#.#.#.#.#.#.|D|)\n");
		printf("|O.O.#.#.#.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.#.#.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==29)
	{
		printf("+------------------------+\n");
		printf("|O.O.#.#.#.#.#.#.#.#.#.|D|)\n");
		printf("|O.#.#.#.#.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.#.#.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==30)
	{
		printf("+------------------------+\n");
		printf("|O.#.#.#.#.#.#.#.#.#.#.|D|)\n");
		printf("|O.#.#.#.#.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|O.#.#.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==31)
	{
		printf("+------------------------+\n");
		printf("|O.#.#.#.#.#.#.#.#.#.#.|D|)\n");
		printf("|O.#.#.#.#.#.#.#.#.#.#.|.|\n");
		printf("|O.......................|\n");
		printf("|#.#.#.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==32)
	{
		printf("+------------------------+\n");
		printf("|O.#.#.#.#.#.#.#.#.#.#.|D|)\n");
		printf("|O.#.#.#.#.#.#.#.#.#.#.|.|\n");
		printf("|#.......................|\n");
		printf("|#.#.#.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==33)
	{
		printf("+------------------------+\n");
		printf("|O.#.#.#.#.#.#.#.#.#.#.|D|)\n");
		printf("|#.#.#.#.#.#.#.#.#.#.#.|.|\n");
		printf("|#.......................|\n");
		printf("|#.#.#.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
	if(k==34)
	{
		printf("+------------------------+\n");
		printf("|#.#.#.#.#.#.#.#.#.#.#.|D|)\n");
		printf("|#.#.#.#.#.#.#.#.#.#.#.|.|\n");
		printf("|#.......................|\n");
		printf("|#.#.#.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
	}
}