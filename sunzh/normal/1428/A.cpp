#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int x1,y1,x2,y2;
int main(){
	T=read();
	while(T--){
		x1=read(),y1=read(),x2=read(),y2=read();
		int detx=abs(x2-x1);
		int dety=abs(y2-y1);
		if(detx&&dety) printf("%d\n",detx+dety+2);
		else printf("%d\n",detx+dety);
	}
}