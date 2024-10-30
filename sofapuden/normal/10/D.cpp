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
			
const int MOD = 998244353;
const int MX = 6e2+5; 
const int mN = -1e9-100;
const ll INF = 1e18;

//tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

vector<vector<array<int,3>>> dp(MX,vector<array<int,3>> (MX,{-1,0,0}));
vi v;
int n, m;
map<int,vector<int>> M;

ll fin(int l, int r){
	if(dp[l][r][0] != -1)return dp[l][r][0];
	int ret = 0;
	int cul = n+1, cur = n+1;
	for(int i = l+1; i <= n; ++i){
		if(upper_bound(M[v[i]].begin(),M[v[i]].end(),r) != M[v[i]].end() && v[i] > v[l]){
			ll x = fin(i,*upper_bound(all(M[v[i]]),r))+1;
			if(x > ret){
				ret = x;
				cul = i;
				cur = *upper_bound(all(M[v[i]]),r);
			}
		}
	}
	if(l != -1)dp[l][r] = {ret,cul,cur};
	return ret;
}

void solve(){
	cin >> n;
	v.resize(n+1);
	v[0] = mN;
	for(int i = 1; i <= n; ++i){
		cin >> v[i];
	}
	cin >> m;
	for(int i = 1; i <= m; ++i){
		int x; cin >> x;
		M[x].pb(i);
	}
	int x = fin(0,0);
	cout << x << '\n';
	int cul = 0;
	int cur = 0;
	while(dp[cul][cur][0]){
		int z = dp[cul][cur][1];
		cur = dp[cul][cur][2];
		cul = z;
		cout << v[cul] << ' ';
	}
	cout << '\n';
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