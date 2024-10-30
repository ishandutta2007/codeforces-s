//#pragma GCC target("avx")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
template<class T> using pq = priority_queue<T,vector<T>,greater<T>>;
#define overload4(_1, _2, _3, _4, name, ...) name
#define overload3(a,b,c,name,...) name
#define rep1(n) for (ll UNUSED_NUMBER = 0; UNUSED_NUMBER < (n); ++UNUSED_NUMBER)
#define rep2(i, n) for (ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i = (n) - 1;i >= 0;i--)
#define rrep2(i,n) for(ll i = (n) - 1;i >= 0;i--)
#define rrep3(i,a,b) for(ll i = (b) - 1;i >= (a);i--)
#define rrep4(i,a,b,c) for(ll i = (a) + ((b)-(a)-1) / (c) * (c);i >= (a);i -= c)
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
template<class... Ts> void in(Ts&... t);
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__; in(__VA_ARGS__)
#define VEC(type, name, size) vector<type> name(size); in(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); in(name)
ll intpow(ll a, ll b){ ll ans = 1; while(b){if(b & 1) ans *= a; a *= a; b /= 2;} return ans;}
ll modpow(ll a, ll b, ll p){ ll ans = 1; a %= p;while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
ll GCD(ll a,ll b) { if(a == 0 || b == 0) return a + b; if(a % b == 0) return b; else return GCD(b,a%b);}
ll LCM(ll a,ll b) { if(a == 0) return b; if(b == 0) return a;return a / GCD(a,b) * b;}
namespace IO{
#define VOID(a) decltype(void(a))
struct setting{ setting(){cin.tie(nullptr); ios::sync_with_stdio(false);fixed(cout); cout.precision(12);}} setting;
template<int I> struct P : P<I-1>{};
template<> struct P<0>{};
template<class T> void i(T& t){ i(t, P<3>{}); }
void i(vector<bool>::reference t, P<3>){ int a; i(a); t = a; }
template<class T> auto i(T& t, P<2>) -> VOID(cin >> t){ cin >> t; }
template<class T> auto i(T& t, P<1>) -> VOID(begin(t)){ for(auto&& x : t) i(x); }
template<class T, size_t... idx> void ituple(T& t, index_sequence<idx...>){
    in(get<idx>(t)...);}
template<class T> auto i(T& t, P<0>) -> VOID(tuple_size<T>{}){
    ituple(t, make_index_sequence<tuple_size<T>::value>{});}
#undef VOID
}
#define unpack(a) (void)initializer_list<int>{(a, 0)...}
template<class... Ts> void in(Ts&... t){ unpack(IO :: i(t)); }
#undef unpack
//constexpr int mod = 1000000007;
constexpr int mod = 998244353;
static const double PI = 3.1415926535897932;
template <class F> struct REC {
    F f;
    REC(F &&f_) : f(forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, forward<Args>(args)...); }};

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int dx2[] = {1,-1,1,-1};
int dy2[] = {-1,1,1,-1};

void bfs(deque<pii> &Q,vvi &dist,vvi &cost,vector<vpii> &pre) {
    int n = dist.size();
    int m = dist[0].size();
    while(!Q.empty()) {
        auto [x,y] = Q.front();
        Q.pop_front();
        rep(i,4) {
            int nx = x + dx2[i],ny = y + dy2[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                if(cost[nx][ny] <= 1 && chmin(dist[nx][ny],dist[x][y] + cost[nx][ny])) {
                    pre[nx][ny] = make_pair(x,y);
                    if(cost[nx][ny]) Q.emplace_back(nx,ny);
                    else Q.emplace_front(nx,ny);
                }
            }
        }
    }
}
int main() {
    INT(TT);
    while(TT--) {
        INT(n,m);
        VEC(string,s,n);
        vvi cost1(n,vi(m,1e9));
        rep(i,n) {
            rep(j,m) {
                if(s[i][j] == '#') cost1[i][j] = 0;
                else if((i + j) % 2) {
                    int flg = 1;
                    rep(k,4) {
                        int ni = i + dx[k],nj = j + dy[k];
                        if(0 <= ni && ni < n && 0 <= nj && nj < m) {
                            if(s[ni][nj] == '#') {
                                flg = 0;
                                break;
                            }
                        }
                    }
                    if(flg) cost1[i][j] = 1;
                }
            }
        }
        vvi dist1(n,vi(m,1e9));
        deque<pii> Q;
        rep(i,n) {
            if(cost1[i][0] <= 1) {
                dist1[i][0] = cost1[i][0];
                if(dist1[i][0]) Q.emplace_back(i,0);
                else Q.emplace_front(i,0);
            }
        }
        vector<vpii> pre1(n,vpii(m,make_pair(-1,-1)));
        bfs(Q,dist1,cost1,pre1);
        vvi cost2(n,vi(m,1e9));
        rep(i,n) {
            rep(j,m) {
                if(s[i][j] == '#') cost2[i][j] = 0;
                else if((i + j) % 2 == 0) {
                    int flg = 1;
                    rep(k,4) {
                        int ni = i + dx[k],nj = j + dy[k];
                        if(0 <= ni && ni < n && 0 <= nj && nj < m) {
                            if(s[ni][nj] == '#') {
                                flg = 0;
                                break;
                            }
                        }
                    }
                    if(flg) cost2[i][j] = 1;
                }
            }
        }
        vvi dist2(n,vi(m,1e9));
        rep(i,n) {
            if(cost2[i][0] <= 1) {
                dist2[i][0] = cost2[i][0];
                if(dist2[i][0]) Q.emplace_back(i,0);
                else Q.emplace_front(i,0);
            }
        }
        vector<vpii> pre2(n,vpii(m,make_pair(-1,-1)));
        bfs(Q,dist2,cost2,pre2);
        int mi1 = 1e9,mi2 = 1e9;
        rep(i,n) {
            chmin(mi1,dist1[i][m-1]);
            chmin(mi2,dist2[i][m-1]);
        }
        if(min(mi1,mi2) == (int)1e9) cout << "NO" << '\n';
        else {
            debug(mi1,mi2);
            if(mi1 >= mi2) {
                swap(mi1,mi2);
                swap(cost1,cost2);
                swap(dist1,dist2);
                swap(pre2,pre1);
            }
            int posx = -1;
            rep(i,n) {
                if(dist1[i][m-1] == mi1) {
                    posx = i;
                    break;
                }
            }
            int posy = m - 1;
            debug(pre1);
            while(posy != -1) {
                s[posx][posy] = '#';
                tie(posx,posy) = pre1[posx][posy];
            }
            cout << "YES" << '\n';
            rep(i,n) cout << s[i] << '\n';
        }
    }
}