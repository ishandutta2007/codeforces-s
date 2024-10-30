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


typedef long double ld;
template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }



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

const ll INF = 1e17;

inline void input(int &a)
{
    a = 0;
    while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-'))
    {}
    char neg = 0;
    if (TEMPORARY_CHAR == '-')
    {
        neg = 1;
        TEMPORARY_CHAR = getchar();
    }

    while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0')
    {
        a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0';
        TEMPORARY_CHAR = getchar();
    }

    if (neg)
        a = -a;
}
inline int nxt() {in(ret); return ret;}

#define x first
#define y second

int main()
{
    const int N = 10000000;
    int lp[N+1];
    int dp[N+1];
    clr(lp);
    clr(dp);
    vector<int> pr;


    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
        dp[i] = 1;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        {
        lp[i * pr[j]] = pr[j];
        dp[i * pr[j]] = i;
    }
    }

    in(n);in(m);
    int q[n], w[m];
    int a[N + 1];
    int b[N + 1];
    clr(b);
    clr(a);

    forn(i,n)
    {
        in(t);
        q[i] = t;
        while (t > 1)
        {
            a[lp[t]]++;
            t = dp[t];
        }
    }
    forn(i,m)
    {
        in(t);
        w[i] = t;
        while (t > 1)
        {
            b[lp[t]]++;
            t = dp[t];
        }
    }
    forn(i,N + 1)
    {
        int r = min(a[i],b[i]);
        a[i] = r;
        b[i] = r;
    }

    cout << n << " " << m << endl;
    forn(i,n)
    {
        int t = q[i];
        int ret = t;
        while (t > 1)
        {
            if (a[lp[t]])
            {
                ret /= lp[t];
                a[lp[t]]--;
            }
            t = dp[t];
        }
        cout << ret << " ";
    }
    cout << endl;
    forn(i,m)
    {
        int t = w[i];
        int ret = t;
        while (t > 1)
        {
            if (b[lp[t]])
            {
                ret /= lp[t];
                b[lp[t]]--;
            }
            t = dp[t];
        }
        cout << ret << " ";
    }
    cout << endl;

    return 0;
}