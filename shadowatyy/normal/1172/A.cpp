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

const int N = 2e5+7;

int n;

int a[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	int g = -1;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		if(a[i]==1)
			g = i;
	}

	int suf = 0;

	if(g!=-1)
	{
		bool ok = 1;

		for(int j = 0; g+j <= n; ++j)
		{
			if(a[g+j]!=1+j)
				ok = 0;
		}

		if(ok)
			suf = n-g+1;
	}

	int ans = n;

	for(int i = 1; i <= n; ++i)
	{
		if(a[i]==0)
			continue;

		ans = max(ans, n + i - (a[i]-1));
	}

	if(suf)
	{
		bool ok = 1;

		for(int i = 1; i < g; ++i)
		{
			if(a[i]==0)
				continue;

			int moge_czekac = a[i]-suf;

			if(i>=moge_czekac)
				ok = 0;
		}

		if(ok)
			ans = n-suf;
	}

	cout << ans << endl;
}