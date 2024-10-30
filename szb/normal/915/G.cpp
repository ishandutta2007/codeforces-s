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
#define Mul(x,y)    x=x*(y)%mod
#define Add(x,y)    x=(x+(y))%mod
#define Max(x,y)	x=x<(y)?(y):x
#define Min(x,y)	x=x>(y)?(y):x
#define E(x) 		return writeln(x),0
#define p(x)		printf("%d\n",x)
#define pp(x,y)		printf("%d %d\n",x,y)
#define ppp(x,y,z)	printf("%d %d %d\n",x,y,z)
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
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1,L,stdin); if (S==T) return '\n';  }   return *S++;    }
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
}using namespace SHENZHEBEI;
const ll N=2000100,mod=1e9+7;
ll bin[N],mu[N],pri[N],f[N],mark[N],ans,n,k;
ll ppow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1)	ans=ans*x%mod;x=x*x%mod;
		k>>=1;
	}return ans;
}
int main(){
	mu[1]=1;
	k=read();	n=read();
	For(i,2,n){
		if (!mark[i])	pri[++pri[0]]=i,mu[i]=-1;
		for(ll j=1;j<=pri[0]&&i*pri[j]<=n;++j){
			mark[i*pri[j]]=1;
			if (!(i%pri[j])){	mu[i*pri[j]]=0;	break;	}
			mu[i*pri[j]]=-mu[i];
		}
	}
	For(i,1,n)	bin[i]=ppow(i,k);
	For(d,1,n)	for(ll j=d;j<=n;j+=d)	(f[j]+=(bin[j/d]-bin[j/d-1])*mu[d])%=mod;
	For(i,1,n)	f[i]=((f[i]+f[i-1])%mod+mod)%mod;
//	For(i,1,n)writeln(f[i]);
	For(i,1,n)	Add(ans,f[i]^i);
	writeln(ans);
}
/*
f[i]=(d=1..i)((i/d)^n)*mu[d];
*/