#include <bits/stdc++.h>

#define __INIT_CC__ ios::sync_with_stdio(false); \
	cin.tie(0);

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define SIZE(_a) (int)_a.size()
#define VSORT(_a) sort(_a.begin(),_a.end())
#define SSORT(_a,_val) sort(_a,_a+(_val))
#define ALL(_a) _a.begin(),_a.end()
#define mt make_tuple
#define _get(_tuple,_i) get<_i>(_tuple)
#define eb emplace_back
 
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll,ll>;
using vpll = vector<pll>;
using vll = vector<ll>;
using pdd = pair<double,double>;
using vpdd = vector<pdd>;
template <typename T> using uset = unordered_set<T>;
template <typename T> using umultiset = unordered_multiset<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename K, typename V> using umultimap = unordered_multimap<K, V>;

constexpr int dr[] = { 1, 0,-1, 0, 1, 1,-1,-1};
constexpr int dc[] = { 0, 1, 0,-1, 1,-1,-1, 1};
constexpr double eps = 1e-9;
constexpr int kInf = 0x7FFFFFFF;
constexpr ll kInfll = 0x7FFFFFFFFFFFFFFFLL;
constexpr double pi = acos(-1);

template <typename T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <typename T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <typename T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <typename T>
inline bool inRange(const T& z, const T& a, const T& b){return a <= z && z <= b;}

void OPEN(const string& in = "input.txt", const string& out = "output.txt")
{
	freopen(in.c_str(), "r", stdin);
	freopen(out.c_str(), "w", stdout);
	return ;
}

//using sokokaleb's template v5.0

constexpr int MAX_N = 200'005;
int arr[MAX_N];
uset<int> uniq;
int maping[205], cnt[205];
ii pq[205];
ii* ptr[205];
int n;

void delet(int x) {
	--(ptr[x]->first);
	while (ptr[x] != pq && ptr[x]->first < (ptr[x] - 1)->first) {
		swap(*(ptr[x]), (*(ptr[x] - 1)));
		int z = ptr[x]->second;
		ptr[x] -= 1;
		ptr[z] += 1;
	}
}

void solve() {
	cin >> n;
	uniq.clear();
	FORN (i, 1, n) {
		cin >> arr[i];
		uniq.insert(arr[i]);
	}
	int z = 0;
	for (const auto& el : uniq) {
		cnt[z] = 0;
		maping[el] = z++;
	}
	FORN (i, 1, n) {
		arr[i] = maping[arr[i]];
		++cnt[arr[i]];
	}
	int sz_uniq = size(uniq);
	int ans = *max_element(cnt, cnt + sz_uniq);
	FOR (calon_a, 0, sz_uniq) {
		FOR (i, 0, sz_uniq) {
			pq[i] = mp(cnt[i], i);
		}
		SSORT(pq, sz_uniq);
		FOR (i, 0, sz_uniq) {
			ptr[pq[i].second] = &pq[i];
		}
		int l = 1, r = n, len_x = 0;
		while (l <= r) {
			while (l <= r && arr[l] != calon_a) {
				delet(arr[l]);
				++l;
			}
			delet(arr[l]); ++l;
			while (l <= r && arr[r] != calon_a) {
				delet(arr[r]);
				--r;
			}
			delet(arr[r]); --r;
			if (l <= r) {
				const auto& p = pq[sz_uniq - 1];
				if (p.first < 0) break;
				++len_x;
				ans = max(ans, len_x * 2 + p.first);
			}
		}
	}
	cout << ans << "\n";
}

int main(int argc, char** argv) {
	__INIT_CC__
	int t;
	cin >> t;
	FORN (tc, 1, t) {
		solve();
	}
}