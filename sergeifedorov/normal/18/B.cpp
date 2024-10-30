#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())
#define sqr(a) (a)*(a)

typedef long long int64;
typedef pair<int,int> pii;

const int inf = (int)1E+9;
const double eps = 1e-9;

const string task = "a";
const string inp = task + ".in";
const string oup = task + ".out";


int main(){
//	freopen(inp.data(), "rt", stdin);
//	freopen(oup.data(),"wt", stdout);

	long long n,d,m,l;
	cin >> n >> d >> m >> l;
	long long l1,r1,now = 0;
	long long idx = 0;
	while (now <= (n-1) * m + l){
		if (now < (idx-1) * m) break;
		if (now > (idx-1) * m + l){
			idx ++;
			continue;
		}
		long long w =  ((idx-1)*m+l - now) / d + 1;
		idx ++;
		now += w * d;
	}
	cout << now << endl;

	return 0;
}