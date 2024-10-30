#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef vector<int> vi;
typedef stringstream ss;
typedef priority_queue<plli, vector<plli>, greater<plli> > PQ;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define clr(t,v) memset((t),(v),sizeof(t))
#define p(a) cout << #a << ": " << a << endl;

#define rep(i,n) for(int i=0,_##i=(n);i<_##i;++i)
#define dwn(i,n) for(int i=(n);--i>=0;)
#define repr(i,l,r) for(int i=(l),_##i=(r);i<_##i;++i)
#define dwnr(i,l,r) for(int i=(r),_##i=(l);--i>=_##i;)
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(),_##i=(a).end();i!=_##i;++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(),_##i=(a).rend();i!=_##i;++i)
const int inf = 1 << 30;
const ll infl = 1LL << 60;
char buf[1000000];
string nextLine() {
	scanf("%[^\n]", buf);
//	getc(stdin);
	scanf("%*c");
	return string(buf);
}
string next() {
	scanf("%s", buf);
	return string(buf);
}

int nextInt() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}
const int MAXN = 200100;
int l[MAXN], r[MAXN];

int conv(char c) {
	return c - 'a';
}
const int MAXC = 100;
vector<pii> arr[MAXC];
bool poss() {
	string a = next(), b = next();
	int x = 0;
	int N = sz(a);
	int M = sz(b);
	bool bad = false;
	rep(i,M) {
		while (x < N && a[x] != b[i]) {
			x++;
		}
		if (x == N) {
			bad = true;
			break;
		}
		l[i] = x;
		x++;
	}
	if (bad)
		return false;
	x = N - 1;
	dwn(i,M) {
		while (x >= 0 && a[x] != b[i])
			x--;
		r[i] = x;
		x--;
	}
	rep(i,M) {
		int p = conv(b[i]);
		arr[p].pb(pii(r[i], l[i]));
	}
	rep(i,N) {
		int p = conv(a[i]);
		vector<pii> &v = arr[p];
		if (sz(v) > 0) {
			if (v.back().fi >= i) {
				int x = int(lower_bound(all(v), pii(i, -1)) - v.begin());
				if (v[x].se <= i)
					continue;
			}
		}
		return false;
	}
	return true;
}
int main() {
	cout << (poss() ? "Yes" : "No") << endl;
}