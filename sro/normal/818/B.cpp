#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define LL long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define FILL(a,v) memset((void*)a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define ALL(a) (a).begin(),(a).end()
#define Inf 1e9
#define Mod 1000000007
#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)
#define SZ(a) ((int)(a).size())
#define FI first
#define SE second
#define OVER(a) return puts(a),0
using namespace std;
using namespace __gnu_cxx;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int Uint;
typedef long long INT;
typedef pair<INT,INT> PII;

int a[1000],l[1000],n,m;
int you[1000];
vector<int> mei;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d",&l[i]);
	memset(a,-1,sizeof(a));
	for(int i=0;i<m-1;i++)
	{
		int gue;
		if(l[i+1]<=l[i])gue=l[i+1]-l[i]+n;
		else gue=l[i+1]-l[i];
		if(a[l[i]]!=-1&&gue!=a[l[i]])OVER("-1");
		a[l[i]]=gue;
	}
	for(int i=1;i<=n;i++)you[a[i]]=1;
	for(int i=1;i<=n;i++)if(!you[i]) mei.push_back(i);
	int j=0;
	for(int i=1;i<=n;i++)
		if(a[i]==-1)
			a[i]=mei[j++];
	if(j!=SZ(mei))OVER("-1");
	for(int i=1;i<=n;i++)
		printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}