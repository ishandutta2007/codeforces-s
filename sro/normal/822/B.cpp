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
int n,m;
string a,b;
int mxcw=Inf;
vector<int> ed;

int main()
{
	cin>>n>>m>>a>>b;
	for(int i=0;i<=SZ(b)-SZ(a);i++)
	{
		int cw=0;vector<int> hh;
		for(int j=0;j<SZ(a);j++)
			if(b[i+j]!=a[j])
			{
				cw++;
				hh.push_back(j+1);
			}
		if(mxcw>cw)
		{
			mxcw=min(mxcw,cw);
			ed=hh;
		}
	}
	printf("%d\n",mxcw);
	for(int i=0;i<SZ(ed);i++)
		printf("%d%c",ed[i],i==SZ(ed)-1?'\n':' ');
	return 0;
}