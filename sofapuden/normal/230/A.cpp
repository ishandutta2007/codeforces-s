#include<bits/stdc++.h>
#include<unordered_set>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, l; cin >> l >> n;
	vector<pair<int, int>> vp;
	rep(i, 0, n) {
		int tmp1, tmp2; 
		cin >> tmp1 >> tmp2;
		pair<int, int> tmp3;
		tmp3.first = tmp1; tmp3.second = tmp2;
		vp.push_back(tmp3);
	}
	sort(all(vp));
	rep(i, 0, n) {
		if (l <= vp[i].first) {
			cout << "NO\n";
			return 0;
		}
		l += vp[i].second;
	}
	cout << "YES\n";
	return 0;	
}