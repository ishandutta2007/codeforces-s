// {{{ by shik
#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REP1(i, a, b) for (int i = (a); i <= int(b); i++)
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

namespace { namespace shik {

template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%" SCNd64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }

template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%" PRId64, x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }

#ifdef SHIK
#include "dump.hpp"
#else
#define dump(...)
#endif

template<class T, class F = less<T>> void sort_uniq(vector<T> &v, F f = F()) { sort(begin(v), end(v), f); v.resize(unique(begin(v), end(v)) - begin(v)); }
template<class T> inline T bit(T x, int i) { return (x >> i) & 1; }
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

// }}}

const int N=110;
int n,a[N];
uint64_t dp[N][10010];
void main() {
    R(n);
    REP(i,n) R(a[i]);
    sort(a,a+n);
    if ( SZ(set<int>(a,a+n))<=2 ) {
        W(n);
        return;
    }
    dp[0][0]=1;
    int s=0;
    for ( int i=0,j; i<n; i=j ) {
        for ( j=i; j<n && a[i]==a[j]; j++ );
        int c=j-i;
        for ( int x=i; x>=0; x-- ) REP1(y,0,s) {
            int me=dp[x][y];
            REP1(z,1,c) dp[x+z][y+z*a[i]]+=me;
        }
        s+=c*a[i];
    }
    // REP1(i,0,n) REP1(j,0,s) if ( dp[i][j] ) dump(i,j,dp[i][j]);
    int ans=0;
    for ( int i=0,j; i<n; i=j ) {
        for ( j=i; j<n && a[i]==a[j]; j++ );
        int c=j-i;
        REP1(k,1,c) if ( dp[k][k*a[i]]==1 ) chkmax(ans,k);
    }
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}