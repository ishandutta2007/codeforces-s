#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
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


inline void solve(){
	int n=read();
	if (n&1){
		For(i,1,n){
			For(j,i+1,n) printf("%d ",(i+j)&1?1:-1);
		}
		puts("");
	} else {
		For(i,1,n){
			For(j,i+1,n) if ((i&1)&&i+1==j){
				printf("0 ");
			} else printf("%d ",(i+j)&1?1:-1);
		}
		puts("");
	}
}

int main(){
	int T=read();
	while (T--) solve();
}