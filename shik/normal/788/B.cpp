// {{{ by shik
// #include <stdio.h>
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
void _W( const long long &x ) { printf("%" PRId64,x); }
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

struct DJS {
    vector<int> fa,sz;
    void init( int n ) {
        n++; // be nice for 1-index usage
        fa.resize(n);
        sz.resize(n);
        for ( int i=0; i<n; i++ ) sz[fa[i]=i]=1;
    }
    int f( int x ) {
        return x==fa[x]?x:fa[x]=f(fa[x]);
    }
    void u( int a, int b ) {
        a=f(a); b=f(b);
        if ( a==b ) return;
        if ( sz[a]>sz[b] ) swap(a,b);
        fa[a]=b;
        sz[b]+=sz[a];
    }
} djs;

const int N=1e6+10;
int n,m;
LL d[N];
bool l[N];
int main() {
    R(n,m);
    if ( m<2 ) {
        W(0);
        return 0;
    }
    djs.init(n);
    int rt=-1;
    REP(i,m) {
        int a,b;
        R(a,b);
        if ( a==b ) l[a]=1;
        else {
            d[a]++;
            d[b]++;
            djs.u(a,b);
        }
        rt=a;
    }
    assert(rt!=-1);
    REP1(i,1,n) if ( (d[i]>0 || l[i]) && djs.f(i)!=djs.f(rt) ) {
        W(0);
        return 0;
    }
    LL ans=0;
    REP1(i,1,n) ans+=d[i]*(d[i]-1)/2;
    LL cl=0;
    REP1(i,1,n) cl+=l[i];
    ans+=cl*(m-cl);
    ans+=cl*(cl-1)/2;
    W(ans);
    return 0;
}