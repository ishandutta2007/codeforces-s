// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int main(){
    int n,l,a;scanf("%d%d%d",&n,&l,&a);
    int nw=0,ans=0;
    for(int i=0;i<n;i++){
	int t,x;scanf("%d%d",&t,&x);
	ans+=(t-nw)/a;
	nw=t+x;
    }
    ans+=(l-nw)/a;
    printf("%d\n",ans);
}