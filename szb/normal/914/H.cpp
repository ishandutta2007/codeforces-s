#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)		((x)*(x))
#define abs(x)		((x)>0?(x):-(x))
#define Mul(x,y)    (x=1LL*x*(y)%mod)
#define Add(x,y)    (x=(x+(y))%mod)
#define Max(x,y)	(x=(x<(y)?(y):x))
#define Min(x,y)	(x=(x>(y)?(y):x))
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
#define NEG 1
    inline char gc(){   return getchar();	}
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
    inline ld getreal(){	static ld lbc;	scanf("%lf",&lbc);	return lbc;	}
}using namespace SHENZHEBEI;
const ll N=210;
ll m,n,d,mod,c[N][N],f[N][N],g[N],ans;
int main(){
	n=read();m=read();mod=read();f[1][0]=g[1]=1;
	For(i,0,n){c[i][0]=1;For(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;}
	For(i,2,n){
		For(j,1,i)For(k,1,m)Add(f[i][k],f[i-j][k-1]*g[j]%mod*c[i-2][j-1]);//pp(i-j,k-1);
		For(j,0,m-1)Add(g[i],f[i][j]);
	}
	For(i,0,m)For(j,0,m-i)if (j!=1)For(k,1,n)Add(ans,f[k][i]*f[n-k+1][j]);
	writeln(2ll*n*(n-1)%mod*ans%mod);
}
/*

*/