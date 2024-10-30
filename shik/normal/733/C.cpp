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
} while (0)

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
template<typename T, size_t N>
ostream& operator <<( ostream &s, const array<T,N> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

template<typename T>
void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( long long &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }

void R() {}
template<typename T, typename... U>
void R( T& head, U&... tail ) {
    _R(head);
    R(tail...);
}

template<typename T>
void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
template<typename T>
void _W( const vector<T> &x ) {
    for ( auto i=x.cbegin(); i!=x.cend(); i++ ) {
        if ( i!=x.cbegin() ) putchar(' ');
        _W(*i);
    }
}

void W() {}
template<typename T, typename... U>
void W( const T& head, const U&... tail ) {
    _W(head);
    putchar(sizeof...(tail)?' ':'\n');
    W(tail...);
}

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

const int N=514;

int n,m,a[N],b[N];

vector<pair<int,char>> sol;
bool build( int base, int l, int r ) {
    if ( l==r ) return 1;
    bool all_same=1;
    REP1(i,l,r) if ( a[i]!=a[l] ) all_same=0;
    if ( all_same ) return 0;
    int mx=*max_element(a+l,a+r+1);
    REP1(i,l,r) if ( a[i]==mx ) {
        int id=base+i-l;
        if ( i-1>=l && a[i]>a[i-1] ) {
            for ( int j=i-1; j>=l; j-- ) {
                sol.PB({id,'L'});
                id--;
            }
            REP1(j,i+1,r) sol.PB({id,'R'});
            return 1;
        } else if ( i+1<=r && a[i]>a[i+1] ) {
            REP1(j,i+1,r) sol.PB({id,'R'});
            for ( int j=i-1; j>=l; j-- ) {
                sol.PB({id,'L'});
                id--;
            }
            return 1;
        }
    }
    assert(0);
}

bool solve() {
    for ( int i=1,j=1; i<=m; i++ ) {
        int sa=0,st=j;
        while ( j<=n && sa<b[i] ) sa+=a[j++];
        if ( sa!=b[i] ) return 0;
        int ed=j-1;
        if ( !build(i,st,ed) ) return 0;
        if ( i==m && ed!=n ) return 0;
    }
    return 1;
}

int main() {
    R(n);
    REP1(i,1,n) R(a[i]);
    R(m);
    REP1(i,1,m) R(b[i]);
    bool ok=solve();
    if ( ok ) {
        W("YES");
        for ( auto &i:sol ) W(i.first,i.second);
    } else {
        W("NO");
    }
    return 0;
}