#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 
 
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd;
typedef vector<vi> vvi; 

typedef set<int> si;

#define vt vector
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound
#define ts to_string
#define EACH(x, a) for (auto& x: a)

template<class T> void read(T &x){ cin >> x; }
template<class A> void read(vt<A> &v){ EACH(x, v) read(x); }
template<class H, class... T> void read(H& h, T& ...t){ read(h); read(t...); }

str to_string(const char* c){ return (str)c; }
str to_string(char c){ return (str)""+c; }
str to_string(str s){ return s; }
str to_string(bool b){ return b?"True" : "False"; }
template<class A> str to_string(vt<A> v){ str s; EACH(x, v) s+= to_string(x) + " "; return s; }
template<class H, class... T> str to_string(H& h, T& ...t){ str s; s+=to_string(h); s+=" "; s+=to_string(t...); return s; }
void print(str s){ cout << s << "\n"; }
template<class... A> void print(A ...a){ print(to_string(a...)); }


int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); }
str tb(int x) {str ans; int c = x; for(int i = log2(x); i >= 0; --i){if(pow(2,i) <= c){ ans += "1"; c-=pow(2,i); } else { ans += "0"; } } return ans;}
bool ispr(int x){if(x <= 1){return false;} for(int i = 2; i <= sqrt(x); ++i){ if(x%i == 0){ return false; } }return true; } 
			
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18;

//tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

void solve(){
	int n; cin >> n;
	vector<array<int,2>> a, b;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if((i+j)&1){
				a.push_back({i,j});
			}
			else{
				b.push_back({i,j});
			}
		}
	}
	int cn1 = 0, cn2 = 0;
	for(int i = 0; i < n*n; ++i){
		int A; cin >> A;
		if(cn1 == (int)a.size()){
			if(A == 2){
				cout << 3 << " " << b[cn2][0] << " " << b[cn2][1] << endl;
			}
			else{
				cout << 2 << " " << b[cn2][0] << " " << b[cn2][1] << endl;
			}
			cn2++;
		}
		else if(cn2 == (int)b.size()){
			if(A == 1){
				cout << 3 << " " << a[cn1][0] << " " << a[cn1][1] << endl;
			}
			else{
				cout << 1 << " " << a[cn1][0] << " " << a[cn1][1] << endl;
			}
			cn1++;
		}
		else{
			if(A == 2){
				cout << 1 << " " << a[cn1][0] << " " << a[cn1][1] << endl;
				cn1++;
			}
			else{
				cout << 2 << " " << b[cn2][0] << " " << b[cn2][1] << endl;
				cn2++;
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	bool isT = 0;
	if(isT){
		int t; cin >> t; while(t--){
			solve();
		}
		return 0;
	}
	solve();		
	return 0;
}