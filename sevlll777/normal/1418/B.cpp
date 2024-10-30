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
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n), l(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> l[i];
        vector<int> not_blocked;
        for (int i = 0; i < n; i++) {
            if (l[i] == 0) {
                not_blocked.pb(A[i]);
            }
        }
        sort(not_blocked.rbegin(), not_blocked.rend());
        int uk = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (l[i] == 1) {
                cout << A[i] << ' ';
            } else {
                cout << not_blocked[uk++] << ' ';
            }
        }
        cout << '\n';
    }
}