#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2,tune=native")

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
#include <fstream>
#include <numeric>

typedef int_fast64_t ll;
typedef unsigned long long ull;
typedef long double ld;

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

#define int int_fast64_t
//#define DEBUG

std::mt19937 rnd(time(0));

template<typename T>
bool minravno(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool maxravno(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	input(a);
	if (n == 3) {
		int sum = a[0] + a[1] + a[2];
		if (a[0] == sum || a[1] == sum || a[2] == sum)
			cout << "YES\n";
		else
			cout << "NO\n";
		return;
	}
	if (n == 4) {
		bool flag = true;
		int sum = a[0] + a[1] + a[2] + a[3];
		for (int i = 0; i < 4; ++i) {
			sum -= a[i];
			if (a[0] != sum && a[1] != sum && a[2] != sum && a[3] != sum)
				flag = false;
			sum += a[i];
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
		return;
	}
	sort(rall(a));
	int cnt = 0;
	for (auto i : a)
		if (i)
			cnt++;
	if (cnt > 2)
		cout << "NO\n";
	else {
		if (cnt == 2) {
			if (a[0] != -a[n - 1])
				cout << "NO\n";
			else
				cout << "YES\n";
		}
		else
			cout << "YES\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}