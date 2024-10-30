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
#include <complex>

#define int int_fast64_t

using namespace std;

typedef int_fast64_t ll;
typedef unsigned long long ull;
typedef double ld;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<pair<int, int>>> vvpi;
typedef tuple<int, int, int> ti;
typedef vector<tuple<int, int, int>> vti;
typedef set<int> si;
typedef set<pi> spi;
typedef multiset<int> msi;
typedef map<int, int> mii;
typedef unordered_set<int> usi;
typedef priority_queue<int> pqi;
typedef priority_queue<pair<int, int>> pqpi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef queue<int> qi;
typedef queue<pi> qpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define umset unordered_multiset
#define pq priority_queue

//#define x first
//#define y second
//#define DEBUG

std::mt19937 rnd(228);

template<typename T> bool minravno(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T> bool maxravno(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T> void input(T& a, int i = 0) {
	for (; i < a.size(); ++i)
		std::cin >> a[i];
}

template<typename T> void print(const vector<T>& a, int i = 0, char c = ' ') {
	for (; i < a.size(); ++i)
		std::cout << a[i] << c;
}

template<typename T> void prefsum(T a, T& p) {
	p.resize(a.size());
	partial_sum(all(a), p.begin());
}

template<typename T> struct ovec {
	vector<T> a;
	int n;
	ovec(int n_) {
		n = n_;
		a.resize(2 * n + 1);
	}
	T operator[](int i) {
		return a[i + n];
	}
};

template<typename T> T max(vector<T> a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size();
	return *max_element(a.begin() + i, a.begin() + j);
}

const int MAX = 2e5 + 10, MOD = 1e9 + 7;

int power(int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 0) {
		int tmp = power(a, n / 2);
		return tmp * tmp % MOD;
	}
	return power(a, n - 1) * a % MOD;
}

void solve() {
	int n, q;
	cin >> n >> q;
	vi p(MAX, 0);
	for (int i = 2; i < MAX; ++i) {
		if (!p[i]) {
			p[i] = i;
			for (int j = i * i; j < MAX; j += i)
				if (!p[j])
					p[j] = i;
		}
	}
	vector<spi> s(MAX);
	vector<mii> m(MAX);
	vi a(n + 1);
	input(a, 1);
	for (int i = 1; i <= n; ++i) {
		vi b;
		int x = a[i];
		while (x > 1) {
			b.push_back(p[x]);
			x /= p[x];
		}
		for (auto j : b) {
			s[j].erase({ m[j][i], i });
			m[j][i]++;
			s[j].insert({ m[j][i], i });
		}
	}
	int ans = 1;
	for (int i = 2; i < MAX; ++i)
		if (s[i].size() == n) {
			ans *= power(i, s[i].begin()->first);
			ans %= MOD;
		}
	while (q--) {
		int i, x;
		cin >> i >> x;
		vi b;
		while (x > 1) {
			b.push_back(p[x]);
			x /= p[x];
		}
		for (auto j : b) {
			int was = 0;
			if (s[j].size() == n)
				was = s[j].begin()->first;
			s[j].erase({ m[j][i], i });
			m[j][i]++;
			s[j].insert({ m[j][i], i });
			int now = 0;
			if (s[j].size() == n)
				now = s[j].begin()->first;
			ans *= power(j, now - was);
			ans %= MOD;
		}
		cout << ans << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}