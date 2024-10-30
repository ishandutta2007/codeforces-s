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

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}

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

#define dump(...) _dump(#__VA_ARGS__, __VA_ARGS__);

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

// }}}

int main() {
    int n,k,a=0,b=0;
    RI(n,k);
    REP(i,n) {
        int x;
        RI(x);
        if ( x%2==0 ) a++;
        else b++;
    }
    if ( n-1==k ) {
        if ( b%2==0 && b>0 ) b--;
        else a--;
        puts(b%2==1?"Stannis":"Daenerys");
        return 0;
    }
    if ( n==k ) {
        puts(b%2==1?"Stannis":"Daenerys");
        return 0;
    }
    bool win=0;
    int m1=(n-k+1)/2,m2=n-k-m1;
    if ( (n-k)%2==0 ) { // last step is second
        if ( k%2==1 && m1+max(m2-1-b,0)>=a ) win=1;
    } else { // last step is first
        win=1;
        if ( m2+max(m1-1-a,0)>=b ) win=0;
        if ( k%2==0 && m2+max(m1-b,0)>=a ) win=0;
    }
    puts(win?"Stannis":"Daenerys");
    return 0;
}