#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vi v(N);
	rep(i,0,N) cin >> v[i];
	rep(i,0,N) {
		rep(j,0,sz(v)-1) {
			if (abs(v[j] - v[j+1]) >= 2) {
				cout << "NO" << endl;
				return 0;
			}
		}
		int best = 0;
		rep(j,0,sz(v)) {
			if (v[j] > v[best]) best = j;
		}
		v.erase(v.begin() + best);
	}
	cout << "YES" << endl;
}