#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> bool chmax(T& t, const U& u) { if (t < u) { t = u; return 1; } return 0; }
template<class T, class U> bool chmin(T& t, const U& u) { if (t > u) { t = u; return 1; } return 0; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const int maxn = 1010;

int a[maxn][maxn];
int ans[maxn];

int main() {
	int n; cin >> n;
	rep(i, n) {
		rep(j, n) {
			scanf("%d", &a[i][j]);
		}
	}
	ll x = (ll)a[0][1] * a[0][2] / a[2][1];

	int k = 0;
	while ((ll)k * k < x) ++k;
	ans[0] = k;
	for (int i = 1; i < n; ++i) {
		ans[i] = a[0][i] / k;
	}
	rep(i, n) {
		printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}