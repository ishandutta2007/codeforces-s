#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
#define N 100005
int n,x,size;
bool vis[N];
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); size=n;
	rep(i,1,n) {
		read(x);
		if (size>=1&&x==size) {
			printf("%d",x);
			size--;
			for (;size>=1; size--)
				if (!vis[size]) break;
				else printf(" %d",size);
		}
		puts(""); vis[x]=1;
	}
	return 0;
}