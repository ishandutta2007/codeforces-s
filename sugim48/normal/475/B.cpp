#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
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

int main() {
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	if ((s[0] == '>' && s[n - 1] == '<' && t[0] == '^' && t[m - 1] == 'v') || (s[0] == '<' && s[n - 1] == '>' && t[0] == 'v' && t[m - 1] == '^'))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}