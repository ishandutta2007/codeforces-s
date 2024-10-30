#include <bits/stdc++.h>
using namespace std;
 
#ifdef SG
    #include <debug.h>
#else
    #define show(...)
    #define debug(...)
    #define deepen(...)
    #define timer(...)
#endif
 
#define ARG4(_1,_2,_3,_4,...) _4
 
#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)
 
#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)
 
#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())
 
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;
 
const ld pi = 3.1415926535897932384626433832795l;
 
template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}
 
const int INF = 1000000000;
const ll LINF = 3000000000000000000LL;

struct Input {
    int n;
    vi a;
    bool read () {
        if (scanf("%d", &n) != 1) {
            return 0;
        }
        a.resize(n);
        forn(i, n) {
            scanf("%d", &a[i]);
        }
        return 1;
    }
 
    void init (const Input &input) {
        *this = input;
    }
};
 
struct Data: Input {
    vi ans;
    void write () {
        forn(i, 1, n + 1) {
            printf("%d ", ans[i]);
        }
        puts("");
    }
     
    virtual void solve () {}
     
    virtual void clear () {
        *this = Data();
    }
};

struct Solution: Data {
    void solve () {
        set< int > positions;
        ve< pii > pos(n);
        forn(i, n) {
            pos[i] = {a[i], i};
        }
        sort(all(pos));
        ans.assign(n + 1, 0);
        positions.insert(-1);
        positions.insert(n);
        ans[n] = pos[0].fs;
        forn(i, n) {
            int nx = pos[i].fs;
            int l = *(--positions.upper_bound(pos[i].sc));
            int r = *positions.upper_bound(pos[i].sc);
            debug(mt(l, pos[i].sc, r, nx));
            umx(ans[r - l - 1], nx);
            positions.insert(pos[i].sc);
        }
        debug(ans.begin() + 1, ans.end());
        ford(i, 1, n + 1) {
            umx(ans[i - 1], ans[i]);
        }
    }
     
    void clear () {
        *this = Solution();
    }
};

Solution sol;

int main () {
    cout.setf(ios::showpoint | ios::fixed);
    cout.precision(20);
#ifdef SG
    freopen("input.txt", "r", stdin);
    while (sol.read())
    {
        sol.solve();
        sol.write();
        sol.clear();
    }
#else
    sol.read();
    sol.solve();
    sol.write();
#endif
    return 0;
}