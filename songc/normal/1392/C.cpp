#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define Mup(a,x) a=max(a, x)
#define mup(a,x) a=min(a, x)
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define INF (1ll<<60)
#define MOD 1'000'000'007 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
 
int TC, N;
int A[202020];
 
int main(){
	scanf("%d", &TC);
	while (TC--){
		LL ans=0, a, b;
		scanf("%d", &N);
		scanf("%lld", &a);
		for (int i=2; i<=N; i++){
			scanf("%lld", &b);
			ans += max(0ll, a-b);
			a=b;
		} 
		printf("%lld\n", ans);
	}
	return 0;
}