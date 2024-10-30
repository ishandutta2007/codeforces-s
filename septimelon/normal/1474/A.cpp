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

void solve() {
    int n;
    string b;
    cin >> n >> b;
    string a(n, '1');

    for (int i = 1; i < n; ++i) {
        if (a[i - 1] - '0' + b[i - 1] - '0' == 1 + b[i] - '0') {
            a[i] = '0';
        }
        else {
            a[i] = '1';
        }
    }

    cout << a << "\n";
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
}