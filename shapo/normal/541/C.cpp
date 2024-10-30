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

const int MAXN = 1005;

ll ans;
int n;
int to[MAXN];
int used[MAXN];
ll predp[MAXN], per[MAXN];

ll
gcd(ll a, ll b)
{
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::showpoint | ios::fixed);
    cout.precision(20);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> to[i];
    }
    for (int i = 1; i <= n; ++i) {
        memset(used, 0, sizeof(used));
        int cur = i;
        ll sum_len = 0;
        do {
            used[cur] = 1;
            cur = to[cur];
            sum_len++;
        } while (!used[cur]);
        int cur_x = i;
        while (cur_x != cur) {
            cur_x = to[cur_x];
            ++predp[i];
        }
        per[i] = sum_len - predp[i];
    }
    ans = 1ll;
    forn(i, 1, n + 1) {
        ans *= per[i] / gcd(per[i], ans);
    }
    ll cans = ans;
    ll max_pred = *max_element(predp + 1, predp + n + 1);
    while (cans < max_pred) {
        cans += ans;
    }
    cout << cans << '\n';
    return 0;
}