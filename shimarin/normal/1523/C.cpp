#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
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
int top,stk[N];

void solve(){
	int n=read();
	poly a(n);
	FOR(i,0,n) a[i]=read();
	top=0;
	FOR(i,0,n){
		if (a[i]>1){
			while (top&&stk[top]+1!=a[i]) --top;
			++stk[top];
		} else stk[++top]=a[i];
		For(j,1,top){
			printf("%d",stk[j]);
			if (j!=top) printf(".");
		}
		puts("");
	}
}

int main(){
	int T=read();
	while (T--) solve();
}