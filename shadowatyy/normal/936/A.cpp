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

#define double long double

double k, d, t, ans;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cout << fixed << setprecision(15);

	cin >> k >> d >> t;

	double o = ceil(k/d)*d;
	double ile = k+(o-k)/2;
	ans += o*floor(t/ile);
	t -= floor(t/ile)*ile;

	if(t<=k)
		cout << ans+t << endl;
	else
		cout << ans+k+2*(t-k) << endl;
}