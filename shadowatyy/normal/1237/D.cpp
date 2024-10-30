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

const int N = 1<<19;

int n;

int a[N];
int sub[2*N];
int ans[N];
int sp[20][N];

int query(int a, int b)
{
	int len = b-a+1;
	int bit = 31-__builtin_clz(len);
	return min(sp[bit][a], sp[bit][b-(1<<bit)+1]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		a[i+n] = a[i+n+n] = a[i];
	}

	for(int i = 1; i <= 3*n; ++i)
	{
		ans[i] = 3*n+1;
		sp[0][i] = a[i];
	}

	for(int l = 1; l < 20; ++l)
	{
		int len = 1<<l;

		for(int i = 1; i + len - 1 <= 3*n; ++i)
		{
			sp[l][i] = min(sp[l-1][i], sp[l-1][i+len/2]);
		}
	}

	for(int i = 3*n; i >= 1; --i)
	{
		int l = i, r = 3*n;

		while(l<r)
		{
			int m = (l+r)/2;

			if(2*query(l, m)<a[i])
				r = m;
			else
				l = m+1;
		}

		ans[i] = l;
	}

	for(int i = 3*n-1; i >= 1; --i)
	{
		ans[i] = min(ans[i], ans[i+1]);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(ans[i]==3*n)
			cout << -1 << " ";
		else
			cout << ans[i]-i << " ";
	}

	cout << endl;
}