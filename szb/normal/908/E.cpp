#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define fi first
#define se second
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))    
typedef complex<double> E;
namespace SHENZHEBEI{
#define NEG 1
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
const ll mod=1e9+7,N=2010;	char s[N];
ll n,m,c[N][N],sum[N],zyy[N];
int main(){
//	freopen("cf.in","r",stdin);
	n=read();	m=read();
	For(i,1,m){
		readstr(s+1);
		For(j,1,n)	zyy[j]=zyy[j]<<1|(s[j]-'0');
	}
	c[0][0]=1;
	For(i,1,n)	For(j,1,i){
		c[i][j]=(c[i-1][j-1]+c[i-1][j]*j)%mod;
		sum[i]=(sum[i]+c[i][j])%mod;
	}ll now=0,ans=1;
	sort(zyy+1,zyy+n+1);	zyy[n+1]=-1;
	For(i,1,n)	if ((++now)&&(zyy[i]^zyy[i+1]))	ans=ans*sum[now]%mod,now=0;
	writeln(ans);
}