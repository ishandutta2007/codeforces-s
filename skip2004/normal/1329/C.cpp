#include<bits/extc++.h>
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define mp make_pair
#define pb emplace_back
#define ff first
#define ss second
#define iter iterator
using namespace __gnu_pbds;
using namespace std;
#pragma warning("mod is 1e9 + 7")
const int mod = 1e9 + 7, maxn = 1 << 21 | 100;
mt19937 rd(time(0));
inline void flush(){cout.flush();fflush(stdout);}
#define def(a,b) using a = b
def(u64,unsigned long long);def(u32,unsigned);def(ll,long long);
def(ld,long double);def(db,double);def(str,string);
using pr = pair<int,int>;
struct TEMP6_AK{} ed;
template<typename t>using vec=vector<t>;
template<typename t>using heap=__gnu_pbds::priority_queue<t>;
template<typename t>inline istream&operator,(istream&cin,t&x){return cin>>x;}
template<typename t>inline ostream&operator,(ostream&cout,const t&x){return cout<<x;}
inline void operator,(istream&cin,TEMP6_AK){ return ; }
inline void operator,(ostream&cout,TEMP6_AK){ return ; }
template<typename _1,typename _2>inline void up(_1&a,const _2&b){if(a<b)a=b;}
template<typename _1,typename _2>inline void down(_1&a,const _2&b){if(a>b)a=b;}
istream&in=cin;ostream&out=cout;
inline void reduce(int & x){ x += x >> 31 & mod; }
inline void add(int & x,int y){ reduce(x += y - mod); }
inline void dec(int & x,int y){ reduce(x -= y); }
inline void mul(int & x,int y){ x = ll(x) * y % mod; }
inline int pow(int a,int b){ int p=1; for(;b;b>>=1,mul(a,a))if(b&1)mul(p,a); return p; }
inline int inv(int a){return pow(a,mod-2);}
inline int pct(int a){ return __builtin_popcount(a); }
inline int pct(ll a){ return __builtin_popcountll(a); }
inline int ctz(int a){ return __builtin_ctz(a); }
inline int ctz(ll a){ return __builtin_ctzll(a); }
inline int lg2(int a){ return 31 - __builtin_clz(a); }
inline int lg2(ll a){ return 63 - __builtin_clzll(a); }
typedef long long ll;
int g, h;
#define tree Tree
int tree[maxn], can[maxn], maxcan[maxn];
inline void up(int x) {
	if(tree[maxcan[x << 1]] > tree[maxcan[x << 1 | 1]])
		maxcan[x] = maxcan[x << 1];
	else
		maxcan[x] = maxcan[x << 1 | 1];
	can[x] = tree[x << 1] > tree[x << 1 | 1] ? can[x << 1] : can[x << 1 | 1];
	if(!tree[x << 1] && !tree[x << 1 | 1]) {
		can[x] = std::__lg(x) >= g;
	}
	if(can[x]) {
		maxcan[x] = x;
	}
}
inline void pop(int x) {
	for(;;) {
		if(tree[x << 1] == 0 && tree[x << 1 | 1] == 0) {
			tree[x] = 0;
			for(;x >>= 1;) up(x);
			return ;
		}
		if(tree[x << 1] > tree[x << 1 | 1]) {
			tree[x] = tree[x << 1];
			x <<= 1;
		} else {
			tree[x] = tree[x << 1 | 1];
			x = x << 1 | 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false),in.tie(0);
	int t; in,t;
	for(;t--;) {
		in,h,g;
		for(int i = 1;i < 1 << h;++i) {
			cin >> tree[i];
		}
		for(int i = 1 << h;i < 2 << h;++i) tree[i] = 0;
		for(int i = (1 << h) - 1;i >= 1;--i) {
			up(i);
		}
		std::vector<int> vc;
		for(int i = 1 << g;i < 1 << h;++i) {
			vc.pb(maxcan[1]);
			pop(maxcan[1]);
		}
		ll s=  0;
		for(int i = 1;i < 1 << g;++i) s += tree[i];
		cout << s << '\n';
		for(int i : vc) cout << i << ' ';
		cout.put(10);
	}
}