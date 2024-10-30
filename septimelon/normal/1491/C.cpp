#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e18;
const int INF = 1e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> need(n + 1, 0);
    for (int l = n - 1; l >= 0; --l) {
        need[l] = a[l] - 1;
        ll cd = 0;
        for (int i = l + 2; i < n; ++i) {
            if (i - l <= a[l]) {
                ++cd;
            }
            ll del = min(need[i], cd);
            cd -= del;
            need[i] -= del;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += need[i];
        //cout << need[i] << " ";
    }
    //cout << "!\n";

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}