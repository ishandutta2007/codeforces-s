#ifndef LOCAL
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,tune=native")
#endif //LOCAL

#define _SCL_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:256000000")

//#define push_back pb
#define first x
#define second y

#include <cassert>
#include <ciso646>
#include <climits>
#include <cmath>

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <locale>
#include <numeric>
#include <regex>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>
#include <memory>
#include <chrono>

#ifdef LOCAL
//#include <vld.h>
#endif //LOCAL
using namespace std;

//typedef __int128_t ll;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;

#define speedup cout.tie(nullptr);cin.tie(nullptr);ios_base::sync_with_stdio(false)
#define coutdouble cout<<setprecision(20);cout<<fixed

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

#ifdef LOCAL
mt19937 rd(57322);
#else
mt19937 rd((uint)chrono::steady_clock::now().time_since_epoch().count());
#endif
/*------CommentInInteractive--------*/
#ifndef LOCAL
//#define endl '\n'
#endif //LOCAL
/*----------------------------------*/
const int INF = 1000 * 1000 * 1000 + 322;
const ll LLINF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 57;
const int MOD = 1000 * 1000 * 1000 + 7;
const ll FFT_MOD = 998244353;
const int P1E6 = 1336337;
const int P1E3 = 1009;
const ll P1E14 = 100000000000031;
const ll P1E17 = 100000000000000003;
const ld PI = acosl(-1.);//3.1415926535897932384626433832795
const ld EPS = 1e-9;
/*------------------------------------------------IO_OPERATORS---------------------------------------------*/
template<typename T, typename U> inline ostream &operator << (ostream &_out, const pair<T, U> &_p) { _out << _p.first << " " << _p.second; return _out; }
template<typename T, typename U> inline istream &operator >> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const vector<T> &_v) { if (_v.empty()) return _out; _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline istream &operator >> (istream &_in, vector<T> &_v) { for (auto &_i : _v) _in >> _i; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const map<T, U> &_m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second << ')'; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second << ')'; return _out; }
/*--------------------------------------------------IO_FILES-----------------------------------------------*/
const char * infile =
#ifdef LOCAL
"input.txt"
#else
""
#endif //LOCAL
;
const char * outfile =
#ifdef LOCAL
""
#else
""
#endif //LOCAL
;

/*-------------------------------------------------ALLOCATOR----------------------------------------------*/
//#define ALLOC_LOCAL
#ifdef ALLOC_LOCAL
const int ML_ = 200;
char mem_[ML_ * 1024 * 1024];
size_t _ptr = 0, _magic = 21323400;
void * operator new(size_t cnt) { if (_ptr + cnt < sizeof mem_) { _ptr += cnt; return  mem_ + _ptr - cnt; } else { assert(false);  _ptr = cnt + _magic; return mem_ + _magic; } }
void operator delete(void *) {}
#endif //ALLOC_LOCAL
/*-----------------------------------------------------MATH------------------------------------------------*/
inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline int pwm(ll xx, ll pow, int MD) { if (pow < 0) { return pwm(pwm(xx, MD - 2, MD), -pow, MD); } ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; mlt %= MD; } xx *= xx; pow >>= 1; xx %= MD; } return (int)mlt; }
//inline ll gcdex(ll a, ll b, ll &x, ll &y) { if (b == 0) { x = 1; y = 0; return a; }ll xx, yy; ll gc = gcdex(b, a % b, yy, xx); x = xx; y = yy - (a / b) * xx; return gc; }
inline int inv(ll r, int _mod) { return pwm(r % _mod, _mod - 2, _mod); }
/*-----------------------------------------------------CODE------------------------------------------------*/

/*
    /  \
   /\  /\
  /\    /\
*/

const int N = 300 * 1000 + 57;
int dp[2][N];
vector<int> g[N];

void dfs(int v, int p) {
    int siz = sz(g[v]);
    if (p != -1) siz -= 1;
    int mx1 = 0, mx2 = 0;
    dp[0][v] = 1;
    for (auto u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        int tr = dp[0][u] + max(sz(g[u]) - 1, 1);
        //if (sz(g[u]) > 1) {
        //    tr = dp[0][u] + 2;
        //} else {
        //    tr = dp[0][u] + 1;
        //}
        //cerr << u << " -> " << tr << endl;
        dp[0][v] = max(dp[0][v], tr);
        if (tr - 1 > mx1) {
            mx2 = mx1;
            mx1 = tr - 1;
        } else if (tr - 1 > mx2) {
            mx2 = tr - 1;
        }
    }
    dp[1][v] = max(mx1 + mx2 + (siz - 1) + (p != -1), 1);
    //cerr << v << " -> " << mx1 << " " << mx2 << endl;
    //cerr << v << " -> " << dp[0][v] << " " << dp[1][v] << endl;
}

inline void solve() {
    int t;
    cin >> t;

    for (int tt = 0; tt < t; ++tt) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i) {
            g[i].clear();
            dp[0][i] = dp[1][i] = 0;
        }

        for (int i = 0; i < n - 1; ++i) {
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1, -1);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, dp[1][i]);
            ans = max(ans, dp[0][i]);
        }
        cout << ans << endl;
    }
}

int main() {

    if (*infile != '\0')
        (void)freopen(infile, "r", stdin);
    if (*outfile != '\0')
        (void)freopen(outfile, "w", stdout);

    speedup;
    coutdouble;


    //int tst = 1;
    //srand(time(NULL));
    //cin >> tst;
    //scanf("%d", &tst);
    //while (tst-- > 0) {
    //while(true) {
    solve();
    //if ((tst & 0xF) == 0) {
    //cerr << "ok\n";
    //}
    //cerr << "/*-----------------*/\n";
    //}

#ifdef LOCAL
    cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << endl;
#endif // LOCAL

    return 0;
}