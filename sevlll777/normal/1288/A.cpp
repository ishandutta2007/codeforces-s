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
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define pii pair<int, int>
#define tupint tuple<int, int, int>
#define tupint2 tuple<int, int, int, int>
#define str string
using namespace std;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int s = floor(sqrt(b));
        int ans = b;
        for (int i = s - 200; i <= s + 200; i++) {
            if (i >= 0) {
                ans = min(ans, i + (b + i) / (i + 1));
            }
        }
        if (ans <= a) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}