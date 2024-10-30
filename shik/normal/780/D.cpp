// {{{ by shik
#include <stdio.h>
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

struct NaiveTwoSAT {
    int n;
    vector<int> var;
    vector<vector<int>> e;
    void init(int _n) {
        n = _n;
        e.clear();
        e.resize(2 * n);
    }
    int inv(int x) {
        return x ^ 1;
    }
    void add(int a, int b) {
        e[a].push_back(b);
        e[inv(b)].push_back(inv(a));
    }
    void add(int a, int x, int b, int y) {
        add(a * 2 + x, b * 2 + y);
    }
    bool bfs(int u) {
        var[u >> 1] = u & 1;
        vector<int> que = {u};
        for (size_t i = 0; i < que.size(); i++) {
            u = que[i];
            for (int v : e[u]) {
                auto &x = var[v >> 1];
                if (x == -1) {
                    x = v & 1;
                    que.push_back(v);
                } else if (x != (v & 1)){
                    for (int j : que) var[j >> 1] = -1;
                    return false;
                }
            }
        }
        return true;
    }
    bool solve() {
        var.resize(n);
        memset(var.data(), -1, var.size() * sizeof(var[0]));
        for (int i = 0; i < n; i++) if (!bfs(i * 2) && !bfs(i * 2 + 1)) return false;
        return true;
    }
} sat;

const int N=1010;

int n,c[N];
string s[N][2];

int main() {
    R(n);
    REP(i,n) {
        string a,b;
        R(a,b);
        s[i][0]=a.substr(0,3);
        s[i][1]=a.substr(0,2)+b[0];
    }
    sat.init(n);
    REP(i,n) REP(j,n) if ( i!=j ) REP(x,2) REP(y,2) if ( s[i][x]==s[j][y] ) {
        sat.add(i,x,j,y^1);
        if ( x==0 && y==0 ) sat.add(i,1,j,1);
    }
    if ( sat.solve() ) {
        W("YES");
        REP(i,n) W(s[i][sat.var[i]]);
    } else {
        W("NO");
    }
    return 0;
}