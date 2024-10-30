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
#include <complex>
#include <string>
#include <cstring>
#include <random>
#include <queue>
#include <bitset>

// #define int long long
#define dbl long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        if (n == 1) {
            cout << "YES\n";
        } else {
            set<int> heh;
            for (int i = 0; i < n; i++) {
                heh.insert((n + ((n + A[i] % n) % n + i % n) % n));
            }
            if (heh.size() == n) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

}