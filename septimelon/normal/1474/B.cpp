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
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

set<int> prim;

void prep() {
    vector<bool> inc(100000, true);
    for (ll i = 2; i < 100000; ++i) {
        if (!inc[i]) {
            continue;
        }
        prim.insert(i);
        for (ll j = i * i; j < 100000; j += i) {
            inc[j] = false;
        }
    }
}

void solve() {
    int d;
    cin >> d;

    ll div1 = *prim.lower_bound(d + 1);
    ll div2 = *prim.lower_bound(div1 + d);

    cout << min(div1 * div1 * div1, div1 * div2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    prep();

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }
}