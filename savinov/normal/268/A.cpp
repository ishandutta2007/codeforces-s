#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <list>

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
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;
char TEMPORARY_CHAR;
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
    while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){}
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

inline string in_str()
{
    char c;
    string s;
    while ((c = getchar()) != ' ' && (c != '\n') && (c != EOF))
        s += c;
    return s;
}
inline void out_str(string &s)
{
    forn(i, s.length())
        putchar(s[i]);
}
#define x first
#define y second

#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)

#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))

int main()
{
    in(n);
    int c1[n], c2[n];
    forn(i, n)
    {
        c1[i] = nxt();
        c2[i] = nxt();
    }
    int ans = 0;
    forn(i, n)
        forn(j, n)
            if (c1[i] == c2[j])
                ++ans;
    cout << ans << endl;
    return 0;
}