#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(int i=(ll)(x);i<(ll)(y);++i)
#define For(i,x,y)  for(int i=(ll)(x);i<=(ll)(y);++i)
#define FOr(i,x,y)  for(int i=(ll)(x);i>=(ll)(y);--i)
#define pi acos(-1) 
#define mk make_pair
#define pa pair<ll,ll>
#define lf else if
#define IL inline
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define E(x)        return writeln(x),0
#define LL          (long long)
#define p(x)        printf("~%lld~\n",LL(x))
#define pp(x,y)     printf("~~%lld %lld~~\n",LL(x),LL(y))
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",LL(x),LL(y),LL(z))
#define pppp(a,b,c,d)   printf("~~~%lld %lld %lld %lld\n",LL(a),LL(b),LL(c),LL(d))
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
#define GuYue       puts("\nGuYueNa________________________________________________________________________________")
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_; 
#endif 
#define NEG 1
    static const int GYN=2333333;
    char SZB[GYN],*SS=SZB,*TT=SZB;
    inline char gc(){   if (SS==TT){  TT=(SS=SZB)+fread(SZB,1,GYN,stdin); if (SS==TT) return '\n';  }   return *SS++;    }
#if NEG
    inline ll read(){    ll x=0,g=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') g=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*g; }
    inline void write(long long x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    void Print(long long *a,int s,int t){For(i,s,t)printf("%lld ",a[i]);}
    void Print(int *a,int s,int t){For(i,s,t)printf("%d ",a[i]);}
    void Print(char *a,int s,int t){For(i,s,t)putchar(a[i]);}
    void writeln(ll x){write(x);puts("");}
    void Min(ll &x,ll y){x=x<y?x:y;}
    void Max(ll &x,ll y){x=x>y?x:y;}
}using namespace SHENZHEBEI;
const ll N=3010,mod=1e9+7;
vector<ll>g[N];
ll f[N][N],inv[N],Inv[N],n,d;
void dfs(ll x){
	For(i,1,n+3)f[x][i]=1;
	rep(i,0,g[x].size()){
		ll to=g[x][i];dfs(to);
		For(j,1,n+3)Mul(f[x][j],f[to][j]);
	}
	For(i,1,n+3)Add(f[x][i],f[x][i-1]);
}
ll ppow(ll x,ll k){
	ll ans=1;for(;k;k>>=1,Mul(x,x))if (k&1)Mul(ans,x);
	return ans;
}
void chazhi(){
	ll ans=0;
	For(i,1,n+1)	Inv[i]=ppow(i,mod-2),
					inv[i]=ppow(-i,mod-2);
	For(i,1,n+1){
		ll tmp=1;
		For(j,1,n+1)if (i^j)Mul(tmp,(d-j)*(i>j?Inv[i-j]:inv[j-i])%mod);
		Mul(tmp,f[1][i]);
		Add(ans,tmp);
	}
	Add(ans,mod);
	writeln(ans);
}
int main(){
	n=read(),d=read();
	For(i,2,n)g[read()].push_back(i);
	dfs(1);chazhi();
}