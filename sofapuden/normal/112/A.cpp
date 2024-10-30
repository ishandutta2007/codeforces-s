#include<bits/stdc++.h>
#include<unordered_set>
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define dep(i,a,b) for(ll i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (ll fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (ll fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	string s1,s2; cin >> s1 >> s2;
	rep(i, 0, s1.length()) {
		if (s1[i] <= 'Z' && s1[i] >= 'A') {
			s1[i] = s1[i] - 'A' + 'a';
		}
		if (s2[i] <= 'Z' && s2[i] >= 'A') {
			s2[i] = s2[i] - 'A' + 'a';
		}
	}
	if (s1 < s2) {
		cout << -1 << endl;
		return 0;
	}
	else if (s2 < s1) {
		cout << 1 << endl;
		return 0;
	}
	else {
		cout << 0 << endl;
		return 0;
	}
}