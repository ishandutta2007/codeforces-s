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

struct Maxflow {
    static const int INF=1e8;
    struct E {
        int to,cap,rev;
        E() {}
        E( int _to, int _cap, int _rev ):to(_to),cap(_cap),rev(_rev) {}
    };
    int n;
    vector< vector<E> > e;
    vector< vector<E>::iterator > cur;
    vector<int> dis;
    void init( int _n ) {
        n=_n;
        e.resize(n);
        cur.resize(n);
        dis.resize(n);
        REP(i,n) e[i].clear();
    }
    void add( int a, int b, int c ) {
        if ( a==b ) return;
        e[a].PB(E(b,c,e[b].size()));
        e[b].PB(E(a,0,e[a].size()-1));
    }
    bool bfs() {
        fill(dis.begin(),dis.end(),-1);
        queue<int> q;
        dis[0]=0; q.push(0);
        while ( !q.empty() && dis[n-1]==-1 ) {
            int p=q.front(); q.pop();
            FOR(it,e[p]) {
                if ( it->cap==0 || dis[it->to]!=-1 ) continue;
                dis[it->to]=dis[p]+1;
                q.push(it->to);
            }
        }
        return dis[n-1]!=-1;
    }
    int go( int p, int c ) {
        if ( p==n-1 ) return c;
        int ret=0;
        for ( auto &it=cur[p]; it!=e[p].end(); it++ ) {
            if ( it->cap==0 || dis[it->to]!=dis[p]+1 ) continue;
            int now=go(it->to,min(it->cap,c-ret));
            ret+=now;
            it->cap-=now;
            e[it->to][it->rev].cap+=now;
            if ( ret==c ) break;
        }
        if ( ret==0 ) dis[p]=-1;
        return ret;
    }
    int maxflow( int ub ) {
        int ret=0;
        while ( bfs() && ret<ub ) {
            REP(i,n) cur[i]=e[i].begin();
            ret+=go(0,INF);
        }
        return ret;
    }
} flow;

const int M=514;
struct E {
    int a,b,c;
} e[M];
int n,m,x;

bool ok( double w ) {
    flow.init(n);
    REP(i,m) if ( e[i].c>=w ) flow.add(e[i].a-1,e[i].b-1,(int)(e[i].c/w));
    int f=flow.maxflow(x);
    dump(w,f);
    return f>=x;
}

int main() {
    R(n,m,x);
    REP(i,m) R(e[i].a,e[i].b,e[i].c);
    double l=1.0/x,r=1000000;
    REP(i,80) {
        double w=(l+r)/2;
        if ( ok(w) ) l=w;
        else r=w;
    }
    double ans=(l+r)/2*x;
    printf("%.14f\n",ans);
    return 0;
}