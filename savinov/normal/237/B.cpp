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

const int N = 1 << 16;

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

struct pp
{
    int num;
    int i, j;
    friend bool operator<(const pp &a, const pp &b)
    {
        return a.num < b.num;
    }
};

int main()
{
    in(n);
    map <int, PII > pp;
    int cnt[n];
    map <PII, int > pos;
    VI to;
    forn(i, n)
        cnt[i] = nxt();
    forn(i, n)
        forn(j, cnt[i])
        {
            in(t);
            pp[t] = mp(i, j);
            pos[mp(i, j)] = t;
            to.pb(t);
        }
    vector <pair < PII, PII > >swaps;
    sort(all(to));
    int i = 0;
    int j = 0;
    forn(tt, to.size())
    {
        if (j == cnt[i])
        {
            ++i;
            j = 0;
        }
        PII cur = mp(i, j);
        PII prev = pp[to[tt]];
        if (prev != cur)
        {
            swaps.pb(mp(cur, prev));
            int k = pos[cur];
            pp[k] = prev;
            pos[prev] = k;
        }
        ++j;
    }
    cout << (int)swaps.size() << endl;
    forn(i, swaps.size())
    {
        cout << swaps[i].x.x + 1 << " " << swaps[i].x.y + 1 << " " << swaps[i].y.x + 1 << " " << swaps[i].y.y + 1<< endl;
    }

    return 0;
}