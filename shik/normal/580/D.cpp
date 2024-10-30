// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#ifdef SHIK
template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0);

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

inline int bit( int x, int i ) {
    return (x>>i)&1;
}

inline void chkmax( LL &a, LL b ) {
    if ( b>a ) a=b;
}

const int N=18;
int n,m,a[N],e[N][N];
LL dp[1<<N][N];
int main() {
    int ne;
    RI(n,m,ne);
    REP(i,n) RI(a[i]);
    while ( ne-- ) {
        int x,y,c;
        RI(x,y,c);
        e[x-1][y-1]=c;
    }
    REP(i,n) dp[1<<i][i]=a[i];
    REP(i,1<<n) if ( i ) REP(j,n) if ( bit(i,j) ) {
        LL &me=dp[i][j];
        REP(k,n) if ( !bit(i,k) ) chkmax(dp[i|(1<<k)][k],me+a[k]+e[j][k]);
    }
    LL ans=0;
    REP(i,1<<n) REP(j,n) if ( __builtin_popcount(i)==m ) chkmax(ans,dp[i][j]);
    cout<<ans<<endl;
    return 0;
}