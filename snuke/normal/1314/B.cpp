#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
inline int getInt() { int x; scanf("%d",&x); return x;}
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;



int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  if (m == 0) {
    cout<<0<<endl;
    return 0;
  }
  int n2 = 1<<n;
  n2 >>= 1;
  vi a(n2);
  rep(i,m) {
    int ni;
    scanf("%d",&ni);
    --ni;
    a[ni>>1]++;
  }
  vvi dp(n2,vi(4,-INF));
  rep(i,n2) {
    dp[i][0] = 0;
    if (a[i] == 1) {
      // dp[i] = vi(2);
      dp[i][1] = 1;
      dp[i][2] = 1;
    }
    if (a[i] == 2) {
      // dp[i] = vi(1,1);
      dp[i][3] = 1;
    }
  }
  while (sz(dp) > 1) {
    vvi p;
    swap(dp,p);
    while (sz(p)) {
      vi s = p.back(); p.pop_back();
      vi t = p.back(); p.pop_back();
      // if (sz(s) > sz(t)) swap(s,t);
      // vi x;
      // if (sz(t) == 0) {
      // } else if (sz(s) == 1) { // 1,?
      //   int tx = t[0];
      //   if (sz(t) == 2) maxs(tx, t[1]);
      //   x = vi(1, s[0]+tx+3);
      // } else if (sz(s) == 2) { // 2,2
      //   x = vi(1);
      //   maxs(x[0], s[0]+1 + t[1]+2);
      // } else if (sz(t) == 1) { // 0,1
      //   x = vi(1, t[0]);
      // } else { // 0,2
      //   vi x(2);
      //   x[0] = t[0]+1;
      //   x[1] = max(t[1]+2, t[0]+2);
      // }
      vi x(4,-INF);
      x[0] = 0;
      rep(i,4)rep(j,4) {
        int ai = i&1, bi = i>>1;
        int aj = j&1, bj = j>>1;
        if (ai || aj) {
          maxs(x[1], s[i]+t[j]+1);
        }
        if (i || j) {
          int c = 1 + (ai|aj) + (bi|bj);
          maxs(x[2], s[i]+t[j]+c);
        }
        if ((ai || aj) && (ai+bi+aj+bj > 1)) {
          int c = 2 + (bi|bj);
          maxs(x[3], s[i]+t[j]+c);
        }
      }
      dp.pb(x);
    }
  }
  int ans = 0;
  rep(i,4) maxs(ans, dp[0][i]);
  ++ans;
  cout<<ans<<endl;
  return 0;
}