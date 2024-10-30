// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// =========== Book ============ //

int fastio() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cin.tie(0);
  return 0;
}
int __fastio = fastio();

// =========== Solution ============= //


int main() {
  int n;
  cin >> n;
  vector<bool> seen(n);
  cout << 1 << " ";
  int cur = n - 1;
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    seen[x] = true;
    ++ans;
    while (cur >= 0 && seen[cur]) {
      --ans;
      --cur;
    }
    cout << ans << " ";
  }
  cout << "\n";
}