#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n;
		if (n&1)
		{
			cout<<7;
			n-=3;
		}
		else
		{
			cout<<1;
			n-=2;
		}
		for (int i=0;i<n/2;i++)
			printf("1");
		cout<<endl;
	} 
	return ~~(0^_^0);
}