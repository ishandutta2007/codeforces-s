#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define range(i, n) for(ll i = 0; i < n; ++i)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;

//#define _GLIBCXX_DEBUG
//#define DEBUG

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	range(i, t) {
		ll a, b;
		cin >> a >> b;
		if (a == b) {
			cout << "0 0\n";
			continue;
		}
		if (b > a)
			swap(a, b);
		cout << a - b << " " << min(a % (a - b), a - b - ((a % (a - b)))) << "\n";
	}
	return 0;
}