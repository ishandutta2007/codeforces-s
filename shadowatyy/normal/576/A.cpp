#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
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
#define SIZE(x) (int)(x).size()
using namespace std;

int n;

VI res;

bool isPrime(int a)
{
	for(int i = 2; i*i <= a; ++i)
	{
		if(a%i==0)
			return 0;
	}

	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 2; i <= n; ++i)
	{
		if(isPrime(i))
		{
			for(int j = i; j <= n; j *= i)
			{
				res.pb(j);
			}
		}
	}

	cout << res.size() << endl;

	for(auto it:res)
		cout << it << " ";
}