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
#define Inf (2147483647-214748+3647)
#define INF ((long long)1e18+(long long)1e17+(long long)1e16)
#define Mod 1000000007
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
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
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define MASK(a) (1<<(a))
#define MASKX(x,a) ((x)<<(a))
#define BIT(a,b) ((a>>b)&1)
#define cddx(a) priority_queue<a >
#define cxdd(a) priority_queue<a,vector<a >,greater<a > >
using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int uint;
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

INT a[4][4],b[4][4],aa,bb;
INT k;
map<PII,PII> mpi;
map<PII,INT> xuh;
PII fssc[50];
INT firstxh,lastxh;
PII zjscore,stscore;

int main()
{
	scanf("%I64d%I64d%I64d",&k,&aa,&bb);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			scanf("%I64d",a[i]+j);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			scanf("%I64d",b[i]+j);
	xuh[mp(aa,bb)]=1;
	PII score=mp(0,0);
	if((aa==3&&bb==2)||(aa==2&&bb==1)||(aa==1&&bb==3))
		score.first++;
	if((bb==3&&aa==2)||(bb==2&&aa==1)||(bb==1&&aa==3))
		score.second++;
	mpi[mp(aa,bb)]=score;
	fssc[1]=score;
	INT i;
	for(i=2;i<=k;i++)
	{
		INT maa=aa,mbb=bb;
		aa=a[maa][mbb];
		bb=b[maa][mbb];
		if((aa==3&&bb==2)||(aa==2&&bb==1)||(aa==1&&bb==3))
			score.first++;
		if((bb==3&&aa==2)||(bb==2&&aa==1)||(bb==1&&aa==3))
			score.second++;
		fssc[i]=score;
		if(xuh.count(mp(aa,bb)))
		{
			firstxh=xuh[mp(aa,bb)];
			lastxh=i;
			PII sc=mpi[mp(aa,bb)];
			zjscore=mp(score.first-sc.first,score.second-sc.second);
			stscore=sc;
			break;
		}
		xuh[mp(aa,bb)]=i;
		mpi[mp(aa,bb)]=score;
	}
	if(i<=k)
	{
		INT xhnum=lastxh-firstxh;
		INT chu=(k-firstxh)/(xhnum),mo=(k-firstxh)%(xhnum);
		score.first=chu*zjscore.first+fssc[mo+firstxh].first;
		score.second=chu*zjscore.second+fssc[mo+firstxh].second;
	}
	printf("%I64d %I64d\n",score.first,score.second);
	return 0;
}