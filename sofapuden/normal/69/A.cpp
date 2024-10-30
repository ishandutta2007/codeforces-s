/*
ID: elias2
TASK: nocows
LANG: C++
*/
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { cout << vec[fl]<< sep; } cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { cout << vec[fl]<< sep; } cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;


int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n; cin >> n;
	int sumx = 0, sumy = 0, sumz = 0;
	rep(i, 0, n) {
		int x, y, z;
		cin >> x >> y >> z;
		sumx += x;
		sumy += y;
		sumz += z;

	}
	cout << (sumx == 0 && sumy == 0&&sumz == 0 ? "YES\n" : "NO\n");
}