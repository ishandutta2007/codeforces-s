#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < (t); ++i)
#define dsrep(i,t,s) for(int i = (t)-1; i >= (s); --i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define bn(x) ((1<<(x))-1)
#define newline puts("")
using namespace std;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using PQ = priority_queue<T,vc<T>,greater<T> >;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int,int>;
using T3 = tuple<int,int,int>;
using vi = vc<int>;
using vvi = vv<int>;
using vl = vc<ll>;
using vp = vc<P>;
using vt = vc<T3>;
int getInt(){int x;scanf("%d",&x);return x;}
vi pm(int n, int s=0) { vi a(n); iota(rng(a),s); return a;}
template<typename T>istream& operator>>(istream&i,vc<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vc<T>&v,const string& d=""){stringstream s;rep(i,sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<typename T>ostream& operator<<(ostream&o,const vc<T>&v){if(sz(v))o<<join(v," ");return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
vc<string> split(const string& s,char d=' '){vc<string> r(1);for(char c:s)if(c==d)r.pb("");else r.back()+=c;return r;}
string operator*(const string& s,int t){return join(vc<string>(t,s));}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>T dup(T x, T y){return (x+y-1)/y;}
template<typename T>ll suma(const vc<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}
template<typename T>void uni(vc<T>& a){sort(rng(a));a.erase(unique(rng(a)),a.end());}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

struct Solver {
  void solve() {
    int n,m;
    scanf("%d%d",&n,&m);
    vvi a(n,vi(m));
    cin>>a;
    vp p;
    rep(i,n)rep(j,m) p.eb(a[i][j],i*m+j);
    sort(rng(p));
    vvi ans(n, vi(m,-1));
    rep(pi,m) {
      int i = p[pi].se/m;
      int j = p[pi].se%m;
      ans[i][pi] = a[i][j];
      a[i][j] = -1;
    }
    rep(i,n) {
      int aj = 0;
      rep(j,m) {
        if (ans[i][j] != -1) continue;
        while (a[i][aj] == -1) ++aj;
        ans[i][j] = a[i][aj];
        a[i][aj] = -1;
      }
    }
    cout<<ans<<endl;
  }
};

int main() {
  int ts = 1;
  scanf("%d",&ts);
  rrep(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}