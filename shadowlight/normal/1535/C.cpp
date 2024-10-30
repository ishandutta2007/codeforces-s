#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

void solve() {
  string s;
  cin >> s;
  int n = s.size();

  ll res = 0;

  for (int it = 0; it < 3; ++it) {
    int l = 0;
    int mn = (it == 2 ? -1 : 1);
    for (int i = 0; i <= n; ++i) {
      if (i != n && s[i] == '?') continue;
      if (i == n || (s[i] - '0' + i) % 2 != it) {
        int r = i;
        res += (r - l) * (ll) (r - l + 1) / 2 * mn;
        l = i + 1;
      }
    }

  }
  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}