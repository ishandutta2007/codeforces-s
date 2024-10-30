#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
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

bool solve(int w, int m) {
	if (w == 2 || w == 3) return true;
	while (m) {
		if (m % w == 0) m /= w;
		else if (m % w == 1) m = (m - 1) / w;
		else if (m % w == w - 1) m = (m + 1) / w;
		else return false;
	}
	return true;
}

int main() {
	int w, m; cin >> w >> m;
	cout << (solve(w, m) ? "YES" : "NO") << endl;
}