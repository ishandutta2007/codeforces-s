#include<bits/stdc++.h>
using namespace std;
 
 
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
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int sum = 0, q = 0;
	vector<int> a(n);
	vector<int> ans;
	REP(i, n) {
		cin >> a[i];
		sum += a[i];
		if(i == 0 || a[i] * 2 <= a[0])
			q += a[i], ans.emplace_back(i);
	}

	if(sum / 2 + 1 <= q) {
		cout << size(ans) << "\n";
		for(int x : ans) cout << x + 1 << " ";
		cout << "\n";
	}
	else cout << "0\n";

}