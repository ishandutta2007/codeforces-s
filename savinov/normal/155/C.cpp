#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define in(x) int (x); input((x));
#define out(x) cout << (x);

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-11;
char TEMPORARY_CHAR;
// Types
typedef long long ll;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef vector < vector < int > > VVI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int INF = 0x3f3f3f3f;

const int N = 1 << 16;

inline void input(int &a)
{
    a = 0;
    while ((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0')
    {}

    while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0')
    {
        a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0';
        TEMPORARY_CHAR = getchar();
    }
}

#define x first
#define y second

int dp[100002][27];
int n;

bool can[27][27];
string s;


int main()
{

    cin >> s;
    in(k);
    forn(i,26)
        forn(j,26)
            can[i][j] = true;
    forn(i,k)
    {
        string r;
        cin >> r;
        can[r[0]-'a'][r[1]-'a'] = false;
        can[r[1]-'a'][r[0]-'a'] = false;
    }
    n = (int) s.length();
    forn(i,n)
        forn(j,27)
            dp[i+1][j] = 100000;

    dp[0][26] = 0;
    forn(i,n)
    {
        forn(j,27)
                dp[i+1][j] = dp[i][j] + 1;
        forn(j,27)
            if (can[s[i]-'a'][j]&&dp[i][j]<dp[i+1][s[i]-'a']) dp[i+1][s[i]-'a'] = dp[i][j];
    }
    int ans = 1000000;

    forn(j,27)
    {
        ans = min (ans,dp[n][j]);
    }
    cout << ans;
    return 0;
}