#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
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
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;
typedef v(vp) vvp;
typedef pair<P,int> Q;
typedef vector<Q> vq;



int main() {
  int n,x,y;
  scanf("%d%d%d",&n,&x,&y);
  vq p;
  rep(i,n) {
    int a;
    scanf("%d",&a);
    p.pb(Q(P(min(n,dup(x,a)), min(n,dup(y,a))),i+1));
  }

  sort(rng(p));
  reverse(rng(p));

  rep(ti,2) {
    P best(-INF,-1);
    rep(i,n) {
      if ((n-i) >= p[i].fi.fi && best.fi >= p[i].fi.fi) {
        puts("Yes");
        vi xs, ys;
        vi used(n);
        for (int j = i; j < i+p[i].fi.fi; ++j) {
          used[j] = 1;
          xs.pb(p[j].se);
        }
        for (int j = best.se; sz(ys) < p[best.se].fi.se; ++j) {
          if (used[j]) continue;
          ys.pb(p[j].se);
        }
        if (ti) swap(xs,ys);
        cout<<sz(xs)<<" "<<sz(ys)<<endl;
        cout<<xs<<endl;
        cout<<ys<<endl;
        return 0;
      }
      maxs(best, P((n-i)-p[i].fi.se, i));
    }
    rep(i,n) swap(p[i].fi.fi,p[i].fi.se);
  }

  cout<<"No"<<endl;
  return 0;
}