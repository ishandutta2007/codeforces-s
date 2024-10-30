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
#define endl '\n'
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

const int N = 2e5+7;

int n;

VI G[N];

int dep[N];
int a[N];
int gdzie[N];
int par[N];

queue<int> Q;

VI moje;

void bfs()
{
	Q.push(1);

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		moje.pb(v);

		for(auto &it:G[v])
		{
			if(it==par[v])
			{
				swap(it, G[v].back());
				G[v].pop_back();
				break;
			}
		}

		sort(ALL(G[v]), [](int a, int b)
		{
			return gdzie[a]<gdzie[b];
		});

		for(auto it:G[v])
		{
			dep[it] = dep[v]+1;
			par[it] = v;
			Q.push(it);
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

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		gdzie[a[i]] = i;
	}

	bfs();

	for(int i = 1; i < n; ++i)
	{
		if(dep[a[i]]>dep[a[i+1]])
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(a[i]!=moje[i-1])
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
}