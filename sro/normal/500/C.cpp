/*****************
 *   I<3   C++   *
 *  IWANT ANYAC  *
 * ILOVEPROGRAM! *
 *IT'SINTERESTING*
 * ILOVEPROGRAM! *
 *  INCONTESTS   *
 *   GETSCORE    *
 *    ACCODE     *
 *     LETS      *
 *      GO       *
 *Written by:    *
 *    charlieyan *
 *****************/
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <complex.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
#include <conio.h>
#include <numeric>
#include <list>
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
#define fastio ios::sync_with_stdio(0)
#define filei(f) freopen(f,"r",stdin)
#define fileo(f) freopen(f,"w",stdout)
#define MASK(a) (1<<(a))
#define MASKX(x,a) ((x)<<(a))
#define BIT(a,b) ((a>>b)&1)
using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int Uint;
typedef long long INT;
typedef long double ldouble;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;

int cnt=0;
int n,m;
int w[1007],a[1007];
int was[1007];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",w+i);
	for(int i=0;i<m;i++)scanf("%d",a+i),a[i]--;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)was[j]=0;
		for(int j=i-1;j>=0;j--)
		{
			if(a[i]==a[j])break;
			if(was[a[j]])continue;
			was[a[j]]=1;
			cnt+=w[a[j]];
		}
	}
	printf("%d\n",cnt);
	return 0;
}