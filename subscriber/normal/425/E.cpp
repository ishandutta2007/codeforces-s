#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 211111
using namespace std;
typedef pair<int,int> pt;

int n, k;
int dp[555][555], dp2[555][555];
int w[555];

void add(int &x, int &y) {
	x += y;
	if (x >= M) x-= M;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> k;
	w[0] = 1;
	for (int i = 1; i <= n; i++) w[i] = w[i - 1] * 2 % M;
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) for (int d = 0; d <= k + 1; d++) dp2[j][d] = 0;
		for (int j = 0; j <= n; j++) for (int d = 0; d <= k + 1; d++) if (dp[j][d] > 0) {
			if (j > i) {
				int e = i + 1;
				int z = dp[j][d] * 1ll * w[e] % M;
				add(dp2[j][d], z);
				continue;
			}
			int z = (w[i - j + 1] - 1 + M);
			if (z >= M) z -= M;
			z = z * 1ll * w[j] % M;
			z = z * 1ll * dp[j][d] % M;
			add(dp2[i + 1][min(d + 1, k + 1)], z);
			z = dp[j][d] * 1ll * w[j] % M;
			add(dp2[j][d], z);
		}
		for (int j = 0; j <= n; j++) for (int d = 0; d <= k + 1; d++) dp[j][d] = dp2[j][d];
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) add(ans, dp[i][k]);
	cout << ans << endl;
	return 0;

}