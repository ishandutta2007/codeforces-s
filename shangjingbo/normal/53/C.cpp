#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef unsigned long long ULL;
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

struct Tpoint
{
	double x,y;
	Tpoint(){}
	Tpoint(double _x,double _y){x=_x;y=_y;}
	inline void read(){scanf("%lf%lf",&x,&y);}
	inline void show(){printf("%lf %lf\n",x,y);}
	inline double norm(){ return sqrt( sqr(x)+sqr(y) ); }
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x+b.x,a.y+b.y); }
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x-b.x,a.y-b.y); }
inline Tpoint operator *(const Tpoint &a,const double &b){ return Tpoint(a.x*b,a.y*b); }
inline Tpoint operator /(const Tpoint &a,const double &b){ return Tpoint(a.x/b,a.y/b); }
inline double det(const Tpoint &a,const Tpoint &b){ return a.x*b.y-a.y*b.x; }
inline double dot(const Tpoint &a,const Tpoint &b){ return a.x*b.x+a.y*b.y; }

int main()
{
	int n;
	scanf("%d",&n);
	int l=1,r=n;
	for (int i=0;i<n;++i)
	{
		if (i) printf(" ");
		if (i&1) printf("%d",r--);
		else printf("%d",l++);
	}
	puts("");
	
	return 0;
}