#ifndef LOCAL
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,tune=native")
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
#define endl '\n'
#endif //LOCAL
/*----------------------------------*/
const int INF = 1000 * 1000 * 1000 + 322;
const ll LLINF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 57;
constexpr uint MOD = 1000 * 1000 * 1000 + 7;
constexpr uint FFT_MOD = 998244353;
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
const int ML_ = 450;
char mem_[ML_ * 1024 * 1024];
size_t _ptr = 0, _magic = 21323400;
void * operator new(size_t cnt) { if (_ptr + cnt < sizeof mem_) { _ptr += cnt; return  mem_ + _ptr - cnt; } else { assert(false);  _ptr = cnt + _magic; return mem_ + _magic; } }
void operator delete(void *) {}
#endif //ALLOC_LOCAL
/*-----------------------------------------------------MATH------------------------------------------------*/
inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline int pwm(ll xx, ll pow, int MD) { if (pow < 0) { pow = pow % (MD - 1) + MD - 1; } ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; mlt %= MD; } xx *= xx; pow >>= 1; xx %= MD; } return (int)mlt; }
inline ll gcdex(ll a, ll b, ll &x, ll &y) { if (b == 0) { x = 1; y = 0; return a; } ll xx, yy; ll gc = gcdex(b, a % b, yy, xx); x = xx; y = yy - (a / b) * xx; return gc; }
inline int inv(ll r, int _mod) { return pwm(r % _mod, _mod - 2, _mod); }
/*-----------------------------------------------------CODE------------------------------------------------*/

struct choice {
	bool is;
	ll opt11;
	ll opt10;
	ll opt01;
};

choice go(vector<int>& v, int n, int l, int r) {
	choice ans;
	if (v.empty()) {
		ans.is = false;
		return ans;
	} else {
		ans.is = true;
	}

	if (n == 1) {
		if (sz(v) == 4) {
			ans.opt01 = -INF;
			ans.opt11 = 5;
			ans.opt10 = -INF;
			return ans;
		}
		else if (sz(v) == 3) {
			ans.opt11 = 5;
			ans.opt01 = 5;
			ans.opt10 = 5;
			return ans;
		} else if (sz(v) == 2) {
			if (v[0] == l && v[1] == l + 1 || v[0] == r - 2 && v[1] == r - 1) {
				ans.opt01 = 4;
				ans.opt10 = 4;
				ans.opt11 = 4;
				return ans;
			}
			ans.opt11 = 5;
			ans.opt01 = 5;
			ans.opt10 = 5;
			return ans;
		} else if (sz(v) == 1) {
			ans.opt01 = 3;
			ans.opt10 = 2;
			ans.opt11 = -INF;
			return ans;
		} else {
			assert(false);
		}
	}

	auto nv1 = vector<int>(v.begin(), lower_bound(all(v), l + (1 << n)));
	auto nv2 = vector<int>(lower_bound(all(v), l + (1 << n)), v.end());
	auto ch1 = go(nv1, n - 1, l, (l + r) >> 1);
	auto ch2 = go(nv2, n - 1, (l + r) >> 1, r);
	//cerr << "from " << nv1 << ", " << n - 1 << " returned " << ch1.opt01 << ", " << ch1.opt10 << ", " << ch1.opt11 << endl;
	//cerr << "from " << nv2 << ", " << n - 1 << " returned " << ch2.opt01 << ", " << ch2.opt10 << ", " << ch2.opt11 << endl;
	if (ch1.is && ch2.is) {
		ans.opt11 = 
			max({ ch1.opt11 + max({ ch2.opt01, ch2.opt10, ch2.opt11 }), ch2.opt11 + max({ ch1.opt01, ch1.opt10, ch1.opt11 }),
					ch1.opt01 + ch2.opt10, ch1.opt01 + ch2.opt10
			}) + 3;
		ans.opt01 = ch1.opt01 + ch2.opt01 + 2;
		ans.opt10 = ch1.opt10 + ch2.opt10 + 1;
		return ans;
	}
	if (!ch1.is) {
		swap(ch1, ch2);
	}
	ch1.opt11 += 3;
	ch1.opt10 += 1;
	ch1.opt01 += 2;
	return ch1;
}

inline void solve() {
	vector<int> v;
	int n, k;
#ifndef LOCAL
	cin >> n >> k;
#else
	n = 10;
	k = rd() % ((1 << n) + 1);
#endif
	v.resize(k);
#ifndef LOCAL
	cin >> v;
#else
	for (int i = 0; i < k; ++i) {
		v[i] = rd() % (1 << n) + 1;
	}
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	k = sz(v);
#endif
	for (auto &i : v) --i;
	sort(all(v));

	auto ch = go(v, n - 1, 0, (1 << n));
	if (!ch.is) {
		cout << 0 << endl;
		return;
	}
	cout << max({ ch.opt01, ch.opt10, ch.opt11 }) + 1 << endl;
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
	while (true);
#endif // LOCAL

	return 0;
}