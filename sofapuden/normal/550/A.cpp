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

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string s; cin >> s;
	int ab = 0;
	int ba = 0;
	int aba = 0;
	rep(i, 0, s.length() - 1) {
		if (i != s.length() - 2) {
			if ((s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'A')|| (s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'B')) {
				aba++;
				i += 2;
			}
			else if (s[i] == 'A' && s[i + 1] == 'B' && ab== 0) {
				ab = 1;
				i++;
			}
			else if (s[i] == 'B' && s[i + 1] == 'A' && ba == 0) {
				ba = 1;
				i++;
			}
		}
		else if (s[i] == 'A' && s[i + 1] == 'B' && ab == 0) {
			ab = 1;
			i++;
		}
		else if (s[i] == 'B' && s[i + 1] == 'A' && ba == 0) {
			ba = 1;
			i++;
		}
	}
	if (ab + ba + aba >= 2) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	
}