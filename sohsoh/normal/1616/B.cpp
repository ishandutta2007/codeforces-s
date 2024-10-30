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
		int n;
		cin >> n;
		string ans, ans_r;

		bool flag = false, tflag = true;
		char prv;
		
		cin >> prv;
		ans.push_back(prv);

		for (int i = 1; i < n; i++) {
			char c;
			cin >> c;
			if (c > prv || (c == prv && !flag)) tflag = false;
			flag = true;
			prv = c;
			
			if (tflag) ans.push_back(prv);
		}

		ans_r = ans;
		reverse(all(ans_r));
		cout << ans + ans_r << endl;
	}
	return 0;
}