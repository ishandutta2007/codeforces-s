#pragma GCC optimize("Ofast")
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
const ll N=100010,mod=31607;
char s[N],t[N];
ll a[N][6];
ll n;
int main(){
	for(ll T=read();T--;){
		n=read();
		For(i,1,n)For(j,1,5)a[i][j]=read();
		ll cho=1;
		For(i,2,n){
			if (!cho)cho=i;
			else{
				ll sm1=0,sm2=0;
				For(j,1,5)	sm1+=a[cho][j]<a[i][j],
							sm2+=a[cho][j]>a[i][j];
				if (sm1>=3)cho=cho;
				else if (sm2>=3)cho=i;
				else cho=0;
			}
		}
		bool fl=1;
		For(i,1,n)if(i!=cho){
			ll sm=0;
			For(j,1,5)sm+=a[cho][j]<a[i][j];
			if(sm<3)fl=0; 
		}
		if (fl&&cho)write(cho),puts("");
		else puts("-1"); 
	}
}