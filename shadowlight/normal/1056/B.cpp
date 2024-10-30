#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n, m;
    cin >> n >> m;
    vector <ll> cnt(m, 0);
    ll d = n % m;
    for (ll i = 0; i < m; i++) {
        cnt[i * i % m] += n / m;
        if (i && i <= d) {
            cnt[i * i % m]++;
        }
    }
    ll res = 0;
    for (ll i = 0; i < m; i++) {
        //cout << cnt[i] << " ";
        res += cnt[i] * cnt[(m - i) % m];
    }
    //cout << "\n";
    cout << res;
}