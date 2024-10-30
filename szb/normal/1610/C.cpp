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
const ll N=4001000,mod=1e9+7;
ll n,m,a[N],b[N];
bool check(ll x){
	ll cur=0;
	For(i,1,n)if(cur<=a[i]&&x-cur-1<=b[i]&&cur<x)++cur;
	return cur>=x;
}
int main(){
	for(ll T=read();T--;){
		n=read();
		For(i,1,n)b[i]=read(),a[i]=read();
		ll l=0,r=n,ans=0;
		for(;l<=r;){
			ll mid=(l+r)>>1;if (check(mid))l=mid+1,ans=mid;
			else r=mid-1;
		}
		cout<<ans<<endl;
	}
}