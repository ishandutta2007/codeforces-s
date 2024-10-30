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


inline void chkmax( int &a, int b ) {
    if ( b>a ) a=b;
}

const int N=2e5+10;

int n,a[N];

int gmx[N],dp[N],can[N];
bool good[2*N];
LL solve( int g ) {
    REP(i,g) gmx[i]=0;
    REP(i,n) chkmax(gmx[i%g],a[i]);
    dump(VI(gmx,gmx+g));
    REP(i,n) good[i]=(a[i]==gmx[i%g]);
    REP(i,n) good[n+i]=good[i];
    dump(vector<bool>(good,good+2*n));
    dp[2*n]=0;
    for ( int i=2*n-1; i>=0; i-- ) {
        if ( !good[i] ) dp[i]=0;
        else dp[i]=min(n,dp[i+1]+1);
    }
    REP(i,n+1) can[i]=0;
    REP(i,n) can[dp[i]/g]++;
    for ( int i=n-1; i>=1; i-- ) can[i]+=can[i+1];
    LL ans=0;
    int ub=n/g;
    REP1(i,1,ub) if ( __gcd(i,ub)==1 ) ans+=can[i];
    dump(g,ans);
    return ans;
}

int main() {
    RI(n);
    REP(i,n) RI(a[i]);
    LL ans=0;
    REP1(i,1,n-1) if ( n%i==0 ) ans+=solve(i);
    cout<<ans<<endl;
    return 0;
}