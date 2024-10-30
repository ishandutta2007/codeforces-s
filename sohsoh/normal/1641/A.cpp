#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll n, x;
		cin >> n >> x;
		multiset<ll> st;
		for (int i = 0; i < n; i++) {
			ll f;
			cin >> f;
			st.insert(f);
		}

		int ans = 0;
		while (!st.empty()) {
			ll b = *st.begin();
			st.erase(st.begin());
			auto it = st.find(b * x);
			if (it == st.end()) ans++;
			else st.erase(it);
		}

		cout << ans << endl;
	}
	return 0;
}