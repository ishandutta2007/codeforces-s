#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define range(x) (x).begin(),(x).end()
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int sj(int n)
{
	unsigned int x=rnd();
	return x%n+1;
}
#define rand fst
template<typename typC> void read(register typC &x)
{
	register int c=getchar(),fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
template<typename typC> void read(register typC *a,int num)
{
	for (register int i=1;i<=num;i++) read(a[i]);
}
template<typename typC, typename... Args> void read(typC &first, Args& ... args) {
	read(first);
	read(args...);
}
template<typename typC> void write(register typC x)
{
	if (x<0) putchar('-'),x=-x;
	static int st[100];
	register int tp=1;
	register typC y;st[1]=x%10;x/=10;
	while (x) y=x/10,st[++tp]=x-y*10,x=y;++tp;
	while (--tp) putchar(st[tp]|48);
}
template<typename typC> void write(register typC *a,register int num)
{
	if (num<=0) puts("");
	for (register int i=1;i<=num;i++) write(a[i]),putchar(i==num?10:32);
}
template<typename typC> typC ab(register typC x)
{
	if (x<0) return -x;
	return x;
}
#define space(x) write(x),putchar(32)
#define enter(x) write(x),putchar(10)
#define debug(x,y) printf("%s: ",#x),write(x,y)
const int p=998244353;
const db eps=1e-9;
inline void inc(register int &x,const int y)
{
	if ((x+=y)>=p) x-=p;
}
inline void dec(register int &x,const int y)
{
	if ((x-=y)<0) x+=p;
}
inline int ksm(register int x,register int y)
{
	register int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
priority_queue<int> ONLYYFORRCOPYY;
priority_queue<int,vector<int>,greater<int> > ONLYYFORRCOPYY__;
struct Q
{
	int u,v;
	Q(int a=0,int b=0):u(a),v(b){}
	bool operator<(const Q &o) const {return v<o.v;}
};
const int N=1e3+2,M=1e6+2,inf=1e9;
char s1[N],s2[N];
int a[N],b[N];
int T,n,m,c,i,j,k,x,y,z,ans,la,ksiz,ks;
int main()
{
	cin>>T;
	while (T--)
	{
		cin>>s1+1>>s2+1;
		n=strlen(s1+1),m=strlen(s2+1);ans=0;
		for (i=1;i<=n;i++) for (j=i;j<=n;j++) if (j-i+1<=m)
		{
			x=0;
			for (k=i;k<=j;k++) if (s1[k]!=s2[++x]) break;
			//if (i==1&&j==n) printf("%d\n",k);
			if (k<=j) continue;k=j;
			while (++x<=m&&--k>0) if (s1[k]!=s2[x]) break;
			ans|=(x>m);
		}
		if (ans) puts("YES"); else puts("NO");
	}
}