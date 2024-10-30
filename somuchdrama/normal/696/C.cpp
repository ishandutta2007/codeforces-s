#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>

#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <bitset>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define countbits __builtin_popcountll
#define print(a)            cerr << (a) << '\n'
#define dbg(a)              cerr << #a << " = " << (a) << '\n'
#define dbg2(a, b)          cerr << #a << " = " << (a) << " " << #b << " = " << (b) << '\n'
#define dbg3(a, b, c)       cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << '\n'
#define dbg4(a, b, c, d)    cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << " " << #d << " = " << (d) << '\n'
#define dbg5(a, b, c, d, e) cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << " " << #d << " = " << (d) << " " << #e << " = " << (e) << '\n'
#define PI 3.1415926535897932384626433

using std::cerr;
using std::cin;
using std::cout;

using std::bitset;
using std::deque;
using std::map;
using std::pair;
using std::queue;
using std::set;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;

using std::abs;
using std::max;
using std::min;

using std::sort;
using std::swap;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pul;

struct init{
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()); 
    }
} init;
const ll MOD = 1000 * 1000 * 1000 + 7;
ll binpow(ll a, ll pw) {
    // a %= MOD;
    ll res = 1;
    while (pw) {
        if (pw & 1LL) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        pw >>= 1;
    }
    return res;
}

ll reverse(ll a) {
    return binpow(a, MOD - 2);
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    
    for (ll & i : a) {
        cin >> i;
    }

    ll top = 2;
    bool odd = true;
    for (ll i : a) {
        top = binpow(top, i);
        top %= MOD;
        // dbg3(i, top, binpow(2, i));
        odd &= ((i & 1LL) == 1LL);
    }
    // dbg(odd);
    ll bot = top;
    top += MOD;
    top += (odd ? 1 : -1);
    top %= MOD;
    // dbg(top);
    top *= reverse(3);
    top %= MOD;

    bot *= reverse(2);
    bot %= MOD;

    top = bot - top + MOD;
    top %= MOD;

    cout << top << '/' << bot << '\n';

    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}