#include<vector>
#include<cstdio> 
#include<cstring> 
#include<map>
#include<cmath> 
#include<algorithm>
#include<bitset>
#include<ctime> 
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
bitset<160>a,b,c;
ll n;
int main(){
	n=read();	a[1]=b[0]=1;
	For(i,2,n){
		c=b^(a<<1);
		b=a;	a=c;
	}writeln(n);
	For(i,0,n)	write(a[i]),putchar(' ');	puts("");
	writeln(n-1);
	For(i,0,n-1)	write(b[i]),putchar(' ');
}