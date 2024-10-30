#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 200050;
int n,a[N],b[N],ans;
bool vis[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
void dfs(int u) {
	vis[u]=1;
	if (!vis[a[u]]) dfs(a[u]);
}
int main() {
	read(n);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) read(b[i]);
	int tot=0;
	rep(i,1,n) tot+=b[i];
	rep(i,1,n) if (!vis[i]) dfs(i),ans++;
	printf("%d",((tot%2)^1) + ((ans>1) ? ans : 0));
	return 0;
}