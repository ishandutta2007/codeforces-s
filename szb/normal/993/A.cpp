#include<bits/stdc++.h>
using namespace std;
#define ll int
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define abs(x)      ((x)>0?(x):-(x))
#define Mul(x,y)    (x=(x)*(y)%mod)
#define Add(x,y)    (x=(x+(y))%mod)
#define E(x)        return writeln(x),0
#define p(x)        printf("~%d~\n",x)
#define pp(x,y)     printf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%d %d %d~~~\n",x,y,z)
#define pppp(x,y,z,a)  printf("~~~%d %d %d %d~~~\n",x,y,z,a)
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif
#define NEG 1
    inline char gc(){   return getchar();   }
#if NEG
    inline ll read(){    ll x=0,f=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
    inline ld getreal(){    static ld lbc;  scanf("%lf",&lbc);  return lbc; }
}using namespace SHENZHEBEI;
const ll N=200010;
struct P{
	ll x,y;
	void readln(){x=read()+300,y=read()+300;}
}p[10];
bool operator <(P a,P b){
	return a.x==b.x?(a.y<b.y):(a.x<b.x);
}
ll a,b,c,d,has[1000][1000];
int main(){
	a=read(),b=read();read();read();c=read();d=read();read();read();
	if (a>c)swap(a,c);
	if (b>d)swap(b,d);
	a+=300,b+=300,c+=300,d+=300;
	For(i,a,c)For(j,b,d)has[i][j]=1;
	For(i,1,4)p[i].readln();
	sort(p+1,p+5);
	ll l=p[1].y,r=p[1].y,mid=(p[1].x+p[4].x)>>1;
	For(i,p[1].x,p[4].x){
		For(j,l,r)if (has[i][j])return puts("YES"),0;
		if(i<mid)--l,++r;
		else	++l,--r;
	}puts("NO");
}