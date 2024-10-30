#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

const int N = 1e5+7;

int n, v, ans;

VI G[N];

bitset<N> vis;
bitset<N> del;
int dist[N];
int h[N];

set<PII, greater<PII> > S;

void dfs1(int v)
{
	vis[v] = 1;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			dist[it] = dist[v]+1;
			dfs1(it);
		}
	}
}

void dfs2(int v)
{
	vis[v] = 1;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			dfs2(it);
			h[v] = max(h[v], h[it]+1);
		}
	}
}

void go(int v)
{
	del[v] = 1;
	++ans;
	S.erase(mp(h[v], v));

	for(auto it:G[v])
	{
		if(h[v]==h[it]+1)
		{
			go(it);
			return;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	dfs1(1);
	v = 1;

	for(int i = 1; i <= n; ++i)
	{
		if(dist[i]>dist[v])
			v = i;
	}

	vis.reset();
	dfs2(v);

	for(int i = 1; i <= n; ++i)
	{
		if(i!=v)
			S.insert(mp(h[i], i));
	}

	del[v] = 1;
	ans = 1;
	cout << ans << " ";

	for(int i = 2; i <= n; ++i)
	{
		if(S.empty())
		{
			cout << ans << " ";
			continue;
		}

		int u = S.begin()->nd;
		go(u);
		cout << ans << " ";
	}

}