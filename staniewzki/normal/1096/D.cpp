#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
#define ST first
#define ND second
#define V vector
#define RS resize
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
#define S(a) (int)a.size()

template<class T> void db(T a) { cerr << a; }
template<class L, class R> void db(pair<L, R> a) { cerr << "(" << a.ST << ", " << a.ND << ")"; }
template<class T> void db(V<T> v) { cerr << "{"; REP(i, S(v)) cerr << (i != 0 ? ", " : ""), db(v[i]); cerr << "}"; }
template<class T> void dump(const char *s, T a) { cerr << s << ": "; db(a); cerr << "\n"; }
template<class T, class... TS> void dump(const char *s, T a, TS... x)
{ while(*s != ',') cerr<< *s++; cerr << ": "; db(a); dump(s + 1, x...); }

#ifdef DEBUG
#define DB(...) dump(#__VA_ARGS__, __VA_ARGS__); 
#else
#define DB(...)
#endif

using LL = long long;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<LL>;
using VVI = V<VI>;
using VPII = V<PII>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    VLL v(n);
    REP(i, n) cin >> v[i];

    array<LL, 4> dp = {};
    REP(i, n)
    {
    	if(s[i] == 'h')
    		dp[0] += v[i];
    	if(s[i] == 'a')
    		dp[1] = min(dp[0], dp[1] + v[i]);
    	if(s[i] == 'r')
    		dp[2] = min(dp[1], dp[2] + v[i]);
    	if(s[i] == 'd')
    		dp[3] = min(dp[2], dp[3] + v[i]);

    	DB(i, dp[0], dp[1], dp[2], dp[3]);
    }

    cout << min(min(dp[0], dp[1]), min(dp[2], dp[3])) << "\n";
}