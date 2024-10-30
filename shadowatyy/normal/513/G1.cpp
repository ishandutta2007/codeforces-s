#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 107

int n, k;

int p[N];

double res;

double dp[207][N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(p[i]>p[j])
				dp[0][i][j] = 1;
		}
	}

	for(int l = 0; l < k; ++l)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				for(int x = 1; x <= n; ++x)
				{
					for(int y = x; y <= n; ++y)
					{
						if(x<=i && i<=y && x<=j && j<=y)
							dp[l+1][x+y-i][x+y-j] += dp[l][i][j]/double(n*(n+1)/2);
						else if(x<=i && i<=y)
							dp[l+1][x+y-i][j] += dp[l][i][j]/double(n*(n+1)/2);
						else if(x<=j && j<=y)
							dp[l+1][i][x+y-j] += dp[l][i][j]/double(n*(n+1)/2);
						else
							dp[l+1][i][j] += dp[l][i][j]/double(n*(n+1)/2);

						cerr << dp[l][i][j] << endl;
					}
				}
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			res += dp[k][i][j];
		}
	}

	cout << setprecision(15) << fixed << res;
}