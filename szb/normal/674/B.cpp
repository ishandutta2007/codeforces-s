

#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define abs(x)      ((x)>0?(x):-(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)	((x)=((x)+(y))%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)	((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        printf("~%lld~\n",(long long)x)
#define pp(x,y)     printf("~~%lld %lld~~\n",(long long)x,(long long)y)
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",(long long)x,(long long)y,(long long)z)
#define pppp(a,b,c,d)	printf("~~~%d %d %d %d\n",(long long)a,(long long)b,(long long)c,(long long)d)
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
#define GuYueNa		puts("GYN_________________________________________")
typedef complex<double> E;
namespace _GuYueNa{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif
#define NEG 1
#if NEG
    inline ll read(){    ll x=0,f=1; char ch=getchar();   for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=getchar())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=getchar();   for (;!isdigit(ch);ch=getchar());    for (;isdigit(ch);ch=getchar()aaaaaaaaaaaaa)  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline void writeln(ll x){  write(x);   puts("");   }
}using namespace _GuYueNa;
const ll N=5010;
ll id[N],vis[N],n,k,a,b,c,d;
void Write(ll x){write(x),putchar(' ');}
int main(){
	n=read(),k=read();
	if (k<=n||n==4)return puts("-1"),0;
	a=read(),b=read(),c=read(),d=read();
	id[1]=a,id[2]=c,id[3]=d,id[4]=b;
	vis[a]=vis[b]=vis[c]=vis[d]=1;
	For(i,5,n){For(j,1,n)if (!vis[j]){vis[j]=1,id[i]=j;break;}}
	swap(id[4],id[n]);swap(id[3],id[n-1]);
	For(i,1,n)Write(id[i]);puts("");
	swap(id[1],id[2]),swap(id[n-1],id[n]);
	For(i,1,n)Write(id[i]);puts("");
}
/*
1	2	3	4	5	6	7	8
2	1	3	4	5	6	8	7
*/