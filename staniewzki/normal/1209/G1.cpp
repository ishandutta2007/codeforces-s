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

mt19937 _gen(chrono::system_clock::now().time_since_epoch().count());
int rd(int a, int b) {
	return uniform_int_distribution<int>(a, b)(_gen);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	int max_val = 2e5;
	vector<int> f(max_val + 1, 1e9), l(max_val + 1, -1);
	vector<int> a(n);
	REP(i, n) {
		cin >> a[i];
		f[a[i]] = min(f[a[i]], i);
		l[a[i]] = max(l[a[i]], i);
	}

	vector<int> sum(n);
	REP(i, n) {
		sum[f[a[i]]]++;
		sum[l[a[i]]]--;
	}

	int pref = 0;
	int done = -1;
	int ans = n;
	vector<int> cnt(max_val + 1);
	REP(i, n) {
		pref += sum[i];
		if(pref == 0) {
			int mx = 0;
			FOR(j, done + 1, i)
				mx = max(mx, ++cnt[a[j]]);
			FOR(j, done + 1, i)
				cnt[a[j]]--;
			done = i;
			ans -= mx;
		}
	}

	cout << ans << "\n";
}