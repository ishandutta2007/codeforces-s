#include <iostream>
#include <iomanip>
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
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

const int M = 1000000007;
const int N = 1000022;
int fact[N], inv_fact[N];

int binpow(int a, int x) {
  int ans = 1;
  while (x) {
    if (x % 2) {
      ans *= a;
      ans %= M;
    }
    a *= a;
    a %= M;
    x /= 2;
  }
  return ans;
}

int C(int k, int n) {
  return ((fact[n] * inv_fact[k]) % M * inv_fact[n - k]) % M;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    ans += (i * ((binpow(2, (M - 2) * (n - i)) * C(m - i, n - i - 1)) % M)) % M;
  }
  if (n == m) {
    ans = n;
  }
  ans %= M;
  ans *= k;
  ans %= M;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (i * fact[i - 1]) % M;
    inv_fact[i] = binpow(fact[i], M - 2);
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}