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
typedef vector<int> vi;
typedef stringstream ss;
typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;
typedef pair<pii, int> circ;

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
char buf[1000];
string nextLine(int length = 100) {
	cin.getline(buf, length);
	string s(buf);
	return s;
}
string next(int length = 100) {
	string tmp;
	cin >> tmp;
	return tmp;
}

int nextInt() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}
//int ans();

const int MAXN = 1000000;
int ar[MAXN];
int main() {
	int k = nextInt();
	string s = next();
	if(k==0) {
		ll sum = 0;
		int count = 0;
		repi(c,s) {
			if(*c=='0') {
				count++;
				sum+=count;
			}
			else count = 0;
		}
		cout<<sum<<endl;
		return 0;
	}
	int i = 0;
	rep(x,sz(s)) {
		if (s[x] == '1') {
			ar[i++] = x;
		}
	}
	ll sum = 0;
	rep(x,i) {
		int freleft = ar[x] - (x==0?-1:ar[x - 1]) - 1;
		int y = x + k - 1;
		if (y >= i)
			break;
		ll freright = (y == (i - 1) ? sz(s) :ar[y + 1]) - ar[y] - 1;
		sum += (1 + freleft) * (1 + freright);
	}
	cout << sum << endl;
}