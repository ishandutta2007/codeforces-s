#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n, m; cin >> n >> m;
	vector<bool> a(m);
	while (n--) {
		int x; cin >> x;
		while (x--) {
			int y; cin >> y;
			a[y - 1] = true;
		}
	}
	bool ok = true;
	for (int i = 0; i < m; i++)
		if (!a[i])
			ok = false;
	cout << (ok ? "YES" : "NO") << endl;
}