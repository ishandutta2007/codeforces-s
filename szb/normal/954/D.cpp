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
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define abs(x)      ((x)>0?(x):-(x))
#define Mul(x,y)    (x=1LL*(x)*(y)%mod)
#define Add(x,y)    (x=(x+(y))%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        printf("~%lld~\n",x)
#define pp(x,y)     printf("~~%lld %lld~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",x,y,z)
#define pppp(a,b,c,d)	printf("~~~%d %d %d %d\n",a,b,c,d)
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
const ll N=4333,inf=1e9;
ll vis[N],head[N],nxt[N],vet[N],dis1[N],dis2[N],n,m,s,t,tot,ans;
priority_queue<pa,vector<pa>,greater<pa> >q;
void insert(ll x,ll y){nxt[++tot]=head[x];head[x]=tot;vet[tot]=y;}
void dijstra(ll S,ll *dis){
	For(i,1,n)vis[i]=0,dis[i]=inf;dis[S]=0;q.push(mk(0,S));
	for(;!q.empty();q.pop()){
		ll x=q.top().se;
		if (vis[x])continue;vis[x]=1;
		for(ll i=head[x];i;i=nxt[i])
		if (dis[vet[i]]>dis[x]+1){
			dis[vet[i]]=dis[x]+1;
			q.push(mk(dis[vet[i]],vet[i]));
		}
	}
}
int main(){
	n=read(),m=read(),s=read(),t=read();
	For(i,1,m){
		ll x=read(),y=read();
		insert(x,y),insert(y,x);
	}
	dijstra(s,dis1);
	dijstra(t,dis2);
	For(i,1,n)For(j,i+1,n)
		ans+=((dis1[i]+dis2[j]+1)>=dis1[t])&&((dis1[j]+dis2[i]+1)>=dis1[t]);
	writeln(ans-m);
}