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

using T = int;
struct Node {
	T val, lazy;
	int size = 1;
};

struct Tree {
	vector<Node> tree;
	int size = 1;

	void add_val(int v, T val) {
		tree[v].val += val;
		tree[v].lazy += val;
	}

	T f(T a, T b) { return max(a, b); }

	Tree(int n) {
		while(size < n) size *= 2;
		tree.resize(size * 2);
		for(int i = size - 1; i >= 1; i--)
			tree[i].size = tree[i * 2].size * 2;
	}

	void propagate(int v) {
		REP(i, 2)
			add_val(v * 2 + i, tree[v].lazy);
		tree[v].lazy = 0;
	}

	T query(int l, int r, int v = 1) {
		if(l == 0 && r == tree[v].size - 1)
			return tree[v].val;
		propagate(v);	
		int m = tree[v].size / 2;
		if(r < m)
			return query(l, r, v * 2);
		else if(m <= l)
			return query(l - m, r - m, v * 2 + 1);
		else
			return f(query(l, m - 1, v * 2), query(0, r - m, v * 2 + 1));
	}

	void add(int l, int r, T val, int v = 1) {
		if(l == 0 && r == tree[v].size - 1) {
			add_val(v, val);
			return;
		}
		propagate(v);
		int m = tree[v].size / 2;
		if(r < m)
			add(l, r, val, v * 2);
		else if(m <= l)
			add(l - m, r - m, val, v * 2 + 1);
		else
			add(l, m - 1, val, v * 2), add(0, r - m, val, v * 2 + 1);

		tree[v].val = f(tree[v * 2].val, tree[v * 2 + 1].val);
	}

	int get() {
		return tree[1].val;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> a(m);
	REP(i, m)
		cin >> a[i];

	Tree tree(m);
	REP(i, m) {
		if(a[i] >n - i) {
			cout << "-1\n";
			return 0;
		}

		tree.add(i, i, a[i] + i);
	}

	auto print = [&]() {
		REP(i, m) 
			cout << tree.query(i, i) - a[i] + 1 << " ";
		cout << "\n";
		exit(0);
	};

	if(tree.get() == n) print();

	REP(i, m - 1) {
		tree.add(i + 1, m - 1, a[i] - 1);
		if(tree.get() >= n) {
			int too_much = tree.get() - n;
			tree.add(i + 1, m - 1, -too_much);
			print();
		}
	}

	cout << "-1\n";

}