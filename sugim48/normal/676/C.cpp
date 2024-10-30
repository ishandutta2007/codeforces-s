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
	int N, K; cin >> N >> K;
	string s; cin >> s;
	vector<int> sum(N + 1);
	for (int i = 0; i < N; i++)
		sum[i + 1] = sum[i] + (s[i] == 'a');
	int lb = 0, ub = N + 1;
	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		bool ok = false;
		for (int l = 0; l + mid <= N; l++) {
			int r = l + mid;
			int x = sum[r] - sum[l];
			if (x <= K || mid - x <= K) ok = true;
		}
		if (ok) lb = mid;
		else ub = mid;
	}
	cout << lb << endl;
}