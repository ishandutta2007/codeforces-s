//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
vi eg[maxn];
int dep[maxn];
void dfs(int a, int fa) {
	for (auto v : eg[a]) {
		if (v == fa) continue;
		dep[v] = dep[a] + 1;
		dfs(v, a);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].pb(v);
		eg[v].pb(u);
	}
	dfs(1, 0);
	int cnt[2] = {0, 0};
	for (int i = 1; i <= n; i++)
		cnt[dep[i] & 1]++;
	printf("%d\n", min(cnt[0], cnt[1]) - 1);
	return 0;
}