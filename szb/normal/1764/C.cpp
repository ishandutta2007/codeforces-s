#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y) for(ll i = (ll)(x);i <= (ll)(y);++i)
#define rep(i,x,y) for(ll i = (ll)(x);i < (ll)(y);++i)
#define FOr(i,x,y) for(ll i = (ll)(x);i >= (ll)(y);--i)
#define fi first
#define se second
#define cpy(a,b) memcpy(a,b,sizeof (b))
#define fi first 
#define se second
#define pa pair<ll,ll>
#define y1 yyyyyyyyyyyyyyyyy
#define pb push_back
#define mk make_pair
#define debug puts("@@@@@@@@@@@@@@@@@@@@@@@")
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}
void write(ll x){
	if (x<0)putchar('-'),x=-x;
	if (x>=10)write(x/10);
	putchar(x%10+'0');
}
const ll N=1000100;
char s[N];
ll tot,sum,n,m,a[N],b[N],c[N];
void work(){
	ll ans=0;
	n=read();
	For(i,1,n)a[i]=read();
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;++i) if (a[i]!=a[i-1])
		ans=max(ans,(i-1)*(n-i+1));
	if (a[1]==a[n])ans=max(ans,n/2);
	cout<<ans<<endl;
}
int main(){
//	ll T=read();
	ll T=read();
    for(;T--;){
    	work();
	}
}