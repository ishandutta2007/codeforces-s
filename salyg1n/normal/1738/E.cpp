#pragma GCC optimize("Ofast")

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
#include <list>

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
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
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
template<typename T> void input(T& a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	for (; i <= j; ++i)
		std::cin >> a[i];
}
template<typename T> void print(const vector<T>& a, int i = 0, int j = -1, char c = ' ') {
	if (j == -1)
		j = a.size() - 1;
	for (; i <= j; ++i)
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
	T& operator[](int i) {
		return a[i + n];
	}
};
template<typename T> T min(vector<T> a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	return *min_element(a.begin() + i, a.begin() + j + 1);
}
template<typename T> T max(vector<T> a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	return *max_element(a.begin() + i, a.begin() + j + 1);
}
template<typename T> T sum(vector<T> a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	int res = 0;
	for (; i <= j; ++i)
		res += a[i];
	return res;
}
template<typename T> void sort(T& a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	sort(a.begin() + i, a.begin() + j + 1);
}
template<typename T> void rsort(T& a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	sort(a.begin() + i, a.begin() + j + 1);
	reverse(a.begin() + i, a.begin() + j + 1);
}
template<typename T> void reverse(T& a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	reverse(a.begin() + i, a.begin() + j + 1);
}

using namespace std;

const int MOD = 998244353, MAXN = 1e5 + 10;

int power(int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 0) {
		int tmp = power(a, n / 2);
		return tmp * tmp % MOD;
	}
	return power(a, n - 1) * a % MOD;
}

int fact[MAXN];

int Div(int a, int b) {
	return a * power(b, MOD - 2) % MOD;
}

int cnk(int n, int k) {
	return Div(fact[n], fact[k] * fact[n - k] % MOD);
}

void solve() {
	int n;
	cin >> n;
	vi a(n + 1);
	input(a, 1);
	vi p, s(n + 2);
	prefsum(a, p);
	for (int i = n; i >= 1; --i)
		s[i] = s[i + 1] + a[i];
	int x = 0, j = n, lasti = 0, lastj = n + 1;
	vi st = { 0 }, fn = {n + 1};
	for (int i = 1; i <= n; ++i) {
		if (!a[i])
			continue;
		while (s[j] < p[i] && j > i)
			j--;
		if (j == i)
			break;
		if (s[j] == p[i]) {
			x += 2;
			st.push_back(i);
			fn.push_back(j);
		}
	}
	if (p[fn.back() - 1] - p[st.back()] > 0)
		x++;
	vi b;
	for (int i = 1; i < st.size(); ++i) {
		b.push_back(0);
		for (int j = st[i - 1] + 1; j < st[i]; ++j)
			if (!a[j])
				b.back()++;
			else
				break;
	}
	if (x % 2) {
		b.push_back(0);
		for (int i = st.back() + 1; !a[i]; ++i)
			b.back()++;
	}
	for (int j = (int)fn.size() - 1; j >= 0; --j) {
		b.push_back(0);
		for (int i = fn[j] - 1; i >= 1 && !a[i]; --i)
			b.back()++;
	}
	int ans = 1;
	for (int i = 0; i < b.size(); ++i) {
		int j = b.size() - i - 1;
		if (j < i)
			break;
		if (j == i) {
			int sm = 0;
			for (int k = 0; k <= b[i] + 1; ++k) {
				if (i == 0) {
					if (k <= b[i] - 1) {
						sm += cnk(b[i] - 1, k);
						sm %= MOD;
					}
				}
				else {
					sm += cnk(b[i] + 1, k);
					sm %= MOD;
				}
			}
			ans *= sm;
			ans %= MOD;
		}
		else {
			int sm = 0;
			for (int k = 0; k <= min(b[i], b[j]) + 1; ++k) {
				if (i == 0) {
					if (k <= min(b[i], b[j])) {
						sm += cnk(b[i], k) * cnk(b[j], k);
						sm %= MOD;
					}
				}
				else {
					sm += cnk(b[i] + 1, k) * cnk(b[j] + 1, k);
					sm %= MOD;
				}
			}
			ans *= sm;
			ans %= MOD;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		fact[i] = fact[i - 1] * i % MOD;
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}