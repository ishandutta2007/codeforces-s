//#define _GLIBCXX_DEBUG
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <cassert>
#include <random>
#include <cstring>
#include <climits>
#include <time.h>
#include <chrono>
#include <memory>
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

#pragma GCC optimize("O3")

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& _ : a) cout << _ << " ";
#define input(a) for (auto& _ : a) cin >> _;
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define umset unordered_multiset
#define vll __int128

//#define x first
//#define y second

#define int long long
//#define DEBUG

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	input(a);
	vector<tuple<int, int, int>> ans;
	for (int i = n - 3; i >= 0; --i) {
		if (a[i] > a[i + 1] - a[n - 1]) {
			ans.push_back({ i, i + 1, n - 1 });
			a[i] = a[i + 1] - a[n - 1];
		}
	}
	auto b = a;
	sort(all(b));
	if (a == b) {
		cout << ans.size() << "\n";
		for (auto [x, y, z] : ans)
			cout << x + 1 << " " << y + 1 << " " << z + 1 << "\n";
	}
	else
		cout << "-1\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
 	return 0;
}