#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  for (int i = n - 1; i >= (n - 1) - (m - 1) + 1; i--) {
    if (a[i] != b[m - 1 - ((n - 1) - i)]) {
      cout << "No\n";
      return;
    }
  }
  for (int i = 0; i < (n - 1) - (m - 1) + 1; i++) {
    if (a[i] == b[0]) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No";
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}