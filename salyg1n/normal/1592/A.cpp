//#define _GLIBCXX_DEBUG
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
#include <fstream>
#include <cassert>
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#pragma GCC optimize("O3")

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

//#define int long long
//#define DEBUG

using namespace std;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		ll n, h;
		cin >> n >> h;
		vector<ll> a(n);
		input(a);
		sort(rall(a));
		int k = h / (a[0] + a[1]);
		h -= (a[0] + a[1]) * k;
		k *= 2;
		if (h > 0) {
			k++;
			h -= a[0];
		}
		if (h > 0) {
			k++;
			h -= a[1];
		}
		if (h > 0) {
			k++;
			h -= a[0];
		}
		cout << k << "\n";
	}
	return 0;
}