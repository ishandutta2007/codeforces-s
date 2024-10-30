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

const int N = 1507;

int n, k, bucket, ile;

int ok[N];

void rob(int nr)
{
	static int cnt = 0;

	for(int i = bucket*nr; i < bucket*nr+bucket; ++i)
	{
		cout << "? " << i+1 << endl;
		char ans;
		cin >> ans;

		if(ans=='Y')
			ok[i] = 1;

		++cnt;
	}

	//debug(cnt, 3 * n * n / k / 2);

	assert(cnt <= 3 * n * n / k / 2);
}

int32_t main()
{
	cin >> n >> k;

	bucket = max(k/2, 1);
	ile = n/bucket;

	for(int skok = 1; skok < ile; ++skok)
	{
		for(int i = 0; i < skok; i++)
		{
			if(i+skok>=ile)
				continue;

			cout << "R" << endl;

			for(int j = i; j < ile; j += skok)
			{
				rob(j);
			}
		}
	}

	int ans = 0;

	for(int i = 0; i < n; ++i)
	{
		if(!ok[i])
			++ans;
	}

	cout << "! " << ans << endl;
}