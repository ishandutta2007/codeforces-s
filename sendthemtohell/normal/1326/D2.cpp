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

using hsh = pair<ll, ll>;
const int N = 1000 * 1000 + 57;
hsh val[N];
hsh rval[N];
int ipw1[N];
int ipw2[N];
int pw1[N];
int pw2[N];
int MD1 = rd() % MOD + MOD / 2;
int MD2 = rd() % MOD + MOD / 2;
bool is_pr(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

bool is_pal(int l, int r) {
	hsh hr = val[r];
	hsh hl = val[l];
	hl.x = hl.x * ll(pw1[r - l]) % MD1;
	hl.y = hl.y * ll(pw2[r - l]) % MD2;
	hr.x += MD1 - hl.x;
	hr.x %= MD1;
	hr.y += MD2 - hl.y;
	hr.y %= MD2;


	hsh hhr = rval[r];
	hsh hhl = rval[l];
	hhr.x += MD1 - hhl.x;
	hhr.x %= MD1;
	hhr.y += MD2 - hhl.y;
	hhr.y %= MD2;
	hhr.x = hhr.x * ll(ipw1[l]) % MD1;
	hhr.y = hhr.y * ll(ipw2[l]) % MD2;

	return hhr == hr;
}


bool is_pal(string s) {
	for (int i = 0; i < sz(s) / 2; ++i) {
		if (s[i] != s[sz(s) - i - 1]) return false;
	}
	return true;
}

string stp(string s) {
	string prf;
	int id = 0;
	while (id < sz(s) - id - 1 && s[id] == s[sz(s) - id - 1]) {
		prf.push_back(s[id]);
		++id;
	}

	int mxlen = 0;
	for (int len = 1; id + len <= sz(s) - id; ++len) {
		if (is_pal(s.substr(id, len)) || is_pal(s.substr(sz(s) - id - len, len))) {
			mxlen = len;
		}
	}
	string mid;
	if (is_pal(s.substr(id, mxlen))) {
		mid = s.substr(id, mxlen);
	} else {
		mid = s.substr(sz(s) - id - mxlen, mxlen);
	}
	string suf = prf;
	reverse(all(suf));
	return prf + mid + suf;
}


inline void solve() {
	int t;
	cin >> t;
	while (!is_pr(MD1)) ++MD1;
	while (!is_pr(MD2)) ++MD2;
	ipw1[0] = 1;
	ipw2[0] = 1;
	ipw1[1] = inv(31, MD1);
	ipw2[1] = inv(37, MD2);
	pw1[0] = 1;
	pw2[0] = 1;
	pw1[1] = 31;
	pw2[1] = 37;
	for (int i = 2; i < N; ++i) {
		ipw1[i] = ipw1[i - 1] * ll(ipw1[1]) % MD1;
		ipw2[i] = ipw2[i - 1] * ll(ipw2[1]) % MD2;
		pw1[i] = pw1[i - 1] * ll(pw1[1]) % MD1;
		pw2[i] = pw2[i - 1] * ll(pw2[1]) % MD2;
	}

	while (t--) {
		string s;
		cin >> s;

		string prf;

		for (int i = 0; i < sz(s); ++i) {
			val[i + 1].x = (val[i].x * 31LL + (s[i] - 'a' + 1)) % MD1;
			val[i + 1].y = (val[i].y * 37LL + (s[i] - 'a' + 1)) % MD2;
		}

		for (int i = 0; i < sz(s); ++i) {
			rval[i + 1].x = (rval[i].x + ll(s[i] - 'a' + 1) * pw1[i]) % MD1;
			rval[i + 1].y = (rval[i].y + ll(s[i] - 'a' + 1) * pw2[i]) % MD2;
		}

		int id = 0;
		while (id < sz(s) - id - 1 && s[id] == s[sz(s) - id - 1]) {
			prf.push_back(s[id]);
			++id;
		}

		int mxlen = 0;
		for (int len = 1; id + len <= sz(s) - id; ++len) {
			if (is_pal(id, id + len) || is_pal(sz(s) - id - len, sz(s) - id)) {
				mxlen = len;
			}
		}
		string mid;
		if (is_pal(id, id + mxlen)) {
			mid = s.substr(id, mxlen);
		} else {
			mid = s.substr(sz(s) - id - mxlen, mxlen);
		}
		string suf = prf;
		reverse(all(suf));

		cout << prf << mid << suf << endl;
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
	while (true);
#endif // LOCAL

	return 0;
}