#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 1e5+10;
int n,a[N],cnt,vis[N],pos[N];

int main(){
	n=read();
	For(i,1,2*n) a[i]=read();
	For(i,1,2*n){
		if (!vis[a[i]]) vis[a[i]]=++cnt,pos[a[i]]=cnt*2-1;
		int x=a[i];
		a[i]=pos[a[i]],++pos[x];
	}
	int ans=0;
	For(i,1,n*2) For(j,i+1,2*n) ans+=a[i]>a[j];
	printf("%d\n",ans);
}