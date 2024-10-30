
#include <bits/stdc++.h>
using namespace std;
 
typedef signed i32;
typedef unsigned u32;
typedef long long i64;
typedef unsigned long long u64;
// typedef __int128_t i128;
// typedef __uint128_t u128;
typedef float f32;
typedef double f64;
typedef long double f128;
 
const int maxn = (int)1e5 + 1, maxm = (int)4e6 + 1;
const int maxd = 21, maxc = 26;
const int mod = (int)1e9 + 7, INF = 0x3f3f3f3f;
const f64 pi = acos((f64)-1), eps = 1e-12;
 
inline int sgn(f64 x) {
	return (x > eps) - (x < -eps);
}
 
void solve() {
	int n, dif = 0;
	static int a[maxn];
	vector<int> pos[2];
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for(int i = 0, x; i < n; ++i) {
		scanf("%d", &x);
		a[i] -= x;
		if(!a[i])
			continue;
		dif += a[i];
		pos[a[i] < 0].push_back(i);
	}
	if(dif) {
		puts("-1");
		return;
	}
	vector<pair<int, int> > sol;
	while(!pos[0].empty()) {
		int u = pos[0].back(), v = pos[1].back();
		if(!(--a[u]))
			pos[0].pop_back();
		if(!(++a[v]))
			pos[1].pop_back();
		sol.push_back({u + 1, v + 1});
	}
	printf("%d\n", (int)sol.size());
	for(auto &it: sol)
		printf("%d %d\n", it.first, it.second);
}
 
int main() {
	int T = 1;
	scanf("%d", &T);
	for(int Case = 1; Case <= T; ++Case) {
		// printf("Case #%d: ", Case);
		// printf("%d\n", solve());
		solve();
	}
	return 0;
}