#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)		(x)*(x)
#define abs(x)		(x)>0?(x):-(x)
#define Mul(x,y)    x=x*(y)%mod
#define Add(x,y)    x=(x+(y))%mod
#define Max(x,y)	x=x<(y)?(y):x
#define Min(x,y)	x=x>(y)?(y):x
#define E(x) 		return writeln(x),0
#define p(x)		printf("~%d~\n",x)
#define pp(x,y)		printf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)	printf("~~~%d %d %d~~~\n",x,y,z)
#define f_in(x)		freopen(x".in","r",stdin)
#define f_out(x) 	freopen(x".out","w",stdout)
#define open(x)		f_in(x),f_out(x)
#define fi first
#define se second
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif 
#define NEG 0
    const int L=2333333;
    char SZB[L],*S=SZB,*T=SZB;
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1LL,L,stdin); if (S==T) return '\n';  }   return *S++;    }
#if NEG
    inline ll read(){    ll x=0,f=1LL; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') f=-1LL;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
}using namespace SHENZHEBEI;
const ll N=1LL<<20|111;
ll g[N],h[N],lzh[N],f[100],zyy[N],n,k,n1,n2,lbc,ans;
int main(){
	n=read();k=read();
	rep(i,0,n)rep(j,0,n)if (read())	f[i]|=1LL<<j,f[j]|=1LL<<i;
	n1=n>>1LL,n2=n-n1;
	For(i,0,20)	zyy[1LL<<i]=i;
	rep(i,1LL,(1LL<<n1)){
		lbc=zyy[i&(-i)];
		g[i]=max(g[i-(1LL<<lbc)],g[i&f[lbc]]+1LL);//, 
	}ans=g[(1LL<<n1)-1LL];
	lzh[0]=(1LL<<n1)-1LL;
	rep(i,1LL,(1LL<<n2)){
		lbc=zyy[i&(-i)];
		h[i]=max(h[i-(1LL<<lbc)],h[i&(f[lbc+n1]>>n1)]+1LL);
		lzh[i]=lzh[i-(1LL<<lbc)]&(f[lbc+n1]&((1LL<<n1)-1LL));
		ans=max(ans,h[i]+g[lzh[i]]);
	}printf("%.10f",k*k*(ans-1.0)/ans/2.0);
}