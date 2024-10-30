#pragma GCC optimize("O3")

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

const ll MOD = 998244353;
const ld EPS = 1e-11;
const ld INFLD = 1e20;
const ll INFL = 4e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(643896);

double ReadDouble() {
    string s;
    cin >> s;
    return stol(s);
}

void Erase(set<int>& s, int v) {
    if (s.count(v) > 0) {
        s.erase(v);
    }
}

void Solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> abc;
    for (int i = 0; i + 2 < n; ++i) {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
            abc.insert(i);
        }
    }

    for (int ii = 0; ii < q; ++ii) {
        int pos;
        cin >> pos;
        --pos;
        char nc;
        cin >> nc;
        if (s[pos] != nc) {
            Erase(abc, pos);
            Erase(abc, pos - 1);
            Erase(abc, pos - 2);
            s[pos] = nc;
            for (int i = max(0, pos - 2); i + 2 < min(n, pos + 3); ++i) {
                if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                    abc.insert(i);
                }
            }
        }
        cout << abc.size() << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL

    int t = 1;
    //cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}