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
inline int nxt() {in(ret); return ret;}

#define x first
#define y second

struct cond
{
    int k;
    int time;
    cond (int k=0,int time=0):k(k),time(time){}
    bool friend operator<(const cond &a,const cond &b)
    {
        return (a.k<b.k||(a.k==b.k&&a.time>b.time));
    }
    cond friend operator+(const cond &a,const cond &b)
    {
        return cond(a.k+b.k,a.time+b.time);
    }
};

int main()
{
    cond a[711];
    in(n);
    int len[100];
    forn(i,n)
        len[i] = nxt();
    sort(len,len+n);
    forn(i,n)
    {
        cond tmp[711];
        forn(j,711)
            tmp[j] = cond(a[j].k,a[j].time);
        For(j,len[i],710)
        {
            if (j) tmp[j] = max(tmp[j],tmp[j-1]); 
            tmp[j]=max(tmp[j],a[j-len[i]]+cond(1,max(j-350,0)));
        }
        forn(j,711)
            a[j] = cond(tmp[j].k,tmp[j].time);
    }
    cout << a[710].k << " " << a[710].time;
    return 0;
}