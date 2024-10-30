#include<bits/stdc++.h>
using namespace std;
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.first << ", " << p.second << ")";
}
 
template<class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
	out << "{";
	for(auto it = a.begin(); it != a.end(); it = next(it))
		out << (it != a.begin() ? ", " : "") << *it;
	return out << "}";
}
 
void dump() { cerr << "\n"; }
template<class T, class... Ts> void dump(T a, Ts... x) {
	cerr << a << ", ";
	dump(x...);
}

#ifdef DEBUG
#  define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#  define debug(...) false
#endif
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
template<class T> int size(T && a) { return a.size(); }
 
using LL = long long;
using PII = pair<int, int>;
 

/*
 * Opis: Struktura do dziaa modulo
 * Czas: O(1), dzielenie O(\log mod)
 * Uycie: Ustaw modulo w ostatniej linii. Jeli modulo nie jest const, usu pierwszy wiersz i zadeklaruj mod
 */

template<int mod>
struct mi {
	int val;
	mi() { val = 0; }
	mi(const LL& v) {
		val = (-mod <= v && v <= mod) ? v : v % mod;
		if(val < 0) val += mod;
	}

	friend ostream& operator<<(ostream &os, const mi &a) {
		return os << a.val;
	}
	friend istream& operator>>(istream &is, mi &a) {
		return is >> a.val;
	}

	friend bool operator==(const mi &a, const mi &b) {
		return a.val == b.val;
	}
	friend bool operator!=(const mi &a, const mi &b) {
		return !(a == b);
	}
	friend bool operator<(const mi &a, const mi &b) {
		return a.val < b.val;
	}
	friend bool operator<=(const mi &a, const mi &b) {
		return a.val <= b.val;
	}

	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi &m) {
		if((val += m.val) >= mod) val -= mod;
		return *this;
	}
	mi& operator-=(const mi &m) {
		if((val -= m.val) < 0) val += mod;
		return *this;
	}
	mi& operator*=(const mi &m) {
		val = (LL) val * m.val % mod;
		return *this;
	}
	friend mi qpow(mi a, LL n) {
		if(n == 0) return 1;
		if(n % 2 == 1) return qpow(a, n - 1) * a;
		return qpow(a * a, n / 2);
	}
	friend mi inv(const mi &a) {
		assert(a != 0); return qpow(a, mod - 2);
	}
	mi& operator /=(const mi &m) { 
		return (*this) *= inv(m); 
	}

	friend mi operator+(mi a, const mi &b) { return a += b; }
	friend mi operator-(mi a, const mi &b) { return a -= b; }
	friend mi operator*(mi a, const mi &b) { return a *= b; }
	friend mi operator/(mi a, const mi &b) { return a /= b; }
};
using MI = mi<int(998244353)>;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int m = 1e6;
	vector<MI> pro(m), cnt(m);
	REP(i, n) {
		int k;
		cin >> k;
		MI q = n;
		q *= k;
		q = 1 / q;
		REP(j, k) {
			int a;
			cin >> a;
			pro[a - 1] += q;
			cnt[a - 1] += 1;
		}
	}

	MI res = 0;
	REP(i, m) res += pro[i] * cnt[i];	
	res /= n;
	cout << res << "\n";
}