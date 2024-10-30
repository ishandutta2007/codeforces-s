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

#define int ll
const int N = 4e5+7;

int n, b;

int a[N];

map<int, int> cnt;

VPII val;

int pref[N];
int suf[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> b;

	b *= 8;
	b /= n;
	
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		++cnt[a[i]];
	}

	for(auto it:cnt)
		val.pb(it);

	for(int i = 0; i < siz(val); ++i)
	{
		pref[i] += val[i].nd;
		pref[i+1] += pref[i];
	}

	for(int i = siz(val)-1; i >= 0; --i)
	{
		suf[i] += val[i].nd;

		if(i>0)
			suf[i-1] += suf[i];
	}

	b = min(b, 30ll);
	int seg = 1<<b;
	int ans = inf;

	for(int i = 0; i < siz(val); ++i)
	{
		int curr = 0;

		if(i+seg<siz(val))
			curr += suf[i+seg];

		if(i>0)
			curr += pref[i-1];

		ans = min(ans, curr);
	}

	cout << ans << endl;
}