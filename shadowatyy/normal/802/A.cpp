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
#define flush fflush(stdout)
using namespace std;

#define N 87

int n, k, res;

int a[N];

set<int> curr;

int nast(int b, int d)
{
	for(int i = d+1; i <= n; ++i)
	{
		if(a[i]==b)
			return i;
	}

	return inf;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(curr.find(a[i])!=curr.end())
			continue;
		else if(curr.find(a[i])==curr.end() && curr.size()<k)
		{
			curr.insert(a[i]);
			++res;
		}
		else
		{
			int best = *curr.begin();

			for(auto it:curr)
			{
				if(nast(it, i)>nast(best, i))
					best = it;
			}

			curr.erase(best);
			curr.insert(a[i]);
			++res;
		}
	}

	cout << res;
}