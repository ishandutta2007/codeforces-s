#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); i--)
#define ll long long
#define st f
#define nd s
#define pb PB
#define eb emplace_back
#define mp make_pair				
#define siz(c) SIZ(c)
const int inf = 1e9 + 7;
const LL INF = 1e18L + 7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type
{int o = 0; p << "{"; for (auto c : y) {if (o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if (p > y) p = y;}
sim, class s> void maxi(n &p, s y) {if (p < y) p = y;}

#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "

#ifndef LOCAL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#else
#include</Users/dawid/algo/mac/ordered_set>
#endif

const int N = 1007;

int n;

VI G[N];

int del[N];
int deg[N];

queue<int> Q;

void ans(int x)
{
	cout << "! " << x << endl;
	exit(0);
}

int query(int x, int y)
{
	cout << "? " << x << " " << y << endl;
	int ans;
	cin >> ans;
	return ans;
}

int32_t main()
{
	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		G[x].pb(y);
		G[y].pb(x);
		++deg[x];
		++deg[y];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(deg[i]==1)
		{
			Q.push(i);
		}
	}

	while(siz(Q)>1)
	{
		int x = Q.front();
		Q.pop();
		int y = Q.front();
		Q.pop();

		del[x] = del[y] = 1;

		for(auto it:G[x])
		{
			if(!del[it] && --deg[it]==1)
				Q.push(it);
		}

		for(auto it:G[y])
		{
			if(!del[it] && --deg[it]==1)
				Q.push(it);
		}

		int q = query(x, y);

		if(q==x || q==y)
			ans(q);
	}


	ans(Q.front());
}