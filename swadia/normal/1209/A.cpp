#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int a[MAXN];
bool visit[MAXN];
int main()
{
	cin>>n;
	RPT(i,0,n)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int sum=0;
	RPT(i,0,n)
		if (!visit[i])
		{
			visit[i]=1;
			sum++;
			for (int j=i+1;j<n;j++)
				if (a[j]%a[i]==0)
					visit[j]=1;
		}
	cout<<sum;
	return ~~(0^_^0);
}