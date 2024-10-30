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

const int INF = 1e9;

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

int dp[2][310][310];

inline int pr(int a, int i, int j)
{
    if (i>=0&&j>=0) return dp[a][i][j];
    return -INF;
}


int main()
{
    in(n);
    int a[310][310];
    forn(i,n)
        forn(j,n)
        {
            scanf("%i",&a[i][j]);
            dp[0][i][j] = -INF;
        }

    dp[0][0][0] = a[0][0];
    int cur = 0;
    for(int st = 1; st < 2 * n - 1; st++)
    {
        forn(i,n)
        {
            forn(j,n)
            {
                dp[cur^1][i][j] = -INF;
                if (st<n-1&&(i>st||j>st)) continue;
                if (st>n-1&&(i<st-n+1||j<st-n+1)) continue;
                if (i==j)
                    dp[cur^1][i][j] = a[i][st-i];
                else
                    dp[cur^1][i][j] = a[i][st-i] + a[j][st-j];
                
                

                dp[cur^1][i][j] += max(pr(cur,i-1,j),max(pr(cur,i,j-1),max(pr(cur,i,j),pr(cur,i-1,j-1))));
                
                //cout << dp[cur^1][i][j] << " " << i << " " << j <<" " << st << endl;
                
            }
            
        }
        cur^=1;
    }
    cout << dp[cur][n-1][n-1];


    return 0;
}