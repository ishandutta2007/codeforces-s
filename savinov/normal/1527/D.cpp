//#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline") //Optimization flags
//#pragma GCC option("arch=native", "tune=native", "no-zero-upper", "fast-math", "unsafe-math-optimizations") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")  //Enable AVX

#include <memory>
#include <random>
#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)

using namespace std;

#ifndef LOCAL
#define cerr while(0) cerr
#endif

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
//typedef pair<long long, long long> pii;
typedef vector<long long> vll;
typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef int itn;
typedef unsigned int uint;

const ld PI = 3.1415926535897932384626433832795L;

template<class T>
bool uin(T &, const T &);

template<class T>
bool uax(T &, const T &);

template<class T>
T gcd(T, T);

template<class T>
T lcm(T, T);

template<class _T>
inline string tostr(const _T &);

template<typename T>
void input(T &);

template<typename T = long long>
T nxt();

bool checkp(long long);

template<typename T, typename N>
T pw(T a, N n, T m);

template<typename T>
T inv(T a, T p);

template<class _T>
_T sqr(const _T &x);

template<class T, class... Args>
inline auto make_vec(size_t n, Args &&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, T(args...));
    else
        return vector(n, make_vec<T>(args...));
}

template<class... Args>
inline auto make_vec(size_t n, Args &&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector(n, args...);
    else
        return vector(n, make_vec(args...));
}


int TTT;

void pre() {}

mt19937 gen;

const int INF = 1e9;

int n, l;
vector < vector<int> > g;
vector<int> tin, tout;
vector <int> cnt;
int tt;
vector < vector<int> > up;

void dfs (int v, int p = 0) {
    tin[v] = ++tt;
    up[v][0] = p;
    cnt[v] = 0;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p) {
            dfs(to, v);
            cnt[v] += cnt[to] + 1;
        }
    }

    tout[v] = ++tt;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

void solve(int _) {
    n = nxt();
    l = 20;
    tin.assign(n, 0),  tout.assign(n, 0),  up.resize (n, vector <int>());
    g.assign(n, vector<int>());
    cnt.assign(n, 0);

    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);

    for (int i = 0; i + 1 < n; ++i) {
        int u = nxt();
        int v = nxt();
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs (0);

    auto get = [&](int a, int b) {
        if (a == b) {
            cerr << a << " " << b << endl;
            assert(a == 0);

            ll res = n * (n - 1ll) / 2;
            for (int to : g[a]) {
                res -= (cnt[to] * (cnt[to] + 1ll) / 2);
            }

            return res;
        }

        if (upper(b, a)) swap(a, b);

        if (upper(a, b)) {
            int x = b;
            for (int i=l; i>=0; --i)
                if (! upper (up[x][i], a))
                    x = up[x][i];

            return (cnt[b] + 1ll) * (n - cnt[x] - 1);
        }

        return (cnt[a] + 1ll) * (cnt[b] + 1);
    };

    int A = 0, B = 0;
    vector <ll> q(n + 1);
    q[0] = n * (n - 1ll) / 2;

    for (int i = 1; i <= n; ++i) {
        q[i] = get(A, B);

        if (i == n) break;

        if (upper(B, A)) {
            swap(A, B);
        }

        if (upper(A, B)) {
            if (upper(B, i)) {
                B = i;
            } else if (!upper(i, B) || !upper(A, i)) {
                int L = lca(B, i);
                if (upper(A, L) && A != L) {
                    break;
                }
                A = i;
            }

            continue;
        }

        int L = lca(A, B);
        if (!upper(L, i)) break;
        if (upper(A, i)) {
            A = i;
        } else if (upper(B, i)) {
            B = i;
        } else if (!upper(i, B) && !upper(i, A)) {
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        q[i] -= q[i + 1];
    }

    for (int i = 0; i <= n; ++i) {
        cout << q[i] << " ";
    }
    cout << "\n";

}


int main(int argc, char **argv) {
//    freopen("input", "r", stdin);
//    freopen("output", "w", stdout);

    ::TTT = nxt();
//    nxt();
    pre();

    for (int test = 1; test <= ::TTT; ++test) {
//        cout << "Case #" << test << ": ";
        solve(test);
    }

    return 0;
}

#ifdef LOCAL

struct timer {
    clock_t init;

    timer() {
        init = clock();
    }

    clock_t time() const {
        return clock() - init;
    }

    ~timer() {
        cerr << "Time elapsed: " << (double) (time()) / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    }
};

#include <sys/resource.h>

struct init_str {
    timer t{};

    init_str() {
        freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

        rlimit R{};
        getrlimit(RLIMIT_STACK, &R);
        R.rlim_cur = R.rlim_max;
        setrlimit(RLIMIT_STACK, &R);
    }

} init_global_;

#endif // LOCAL

//#define AUTO_MALLOC 0
#ifdef AUTO_MALLOC
namespace MALLOC {
    const size_t MAX_HEAP = 768 * 1000 * 1000;
    char buf[MAX_HEAP];
    size_t ptr;
}

void *operator new(size_t size) {
    void *result = MALLOC::buf + MALLOC::ptr;
    MALLOC::ptr += size;
    return result;
}

void operator delete(void *ptr) noexcept { /* DO NOTHING */ }

#endif //AUTO_MALLOC

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template<class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

template<class _T>
inline _T sqr(const _T &x) {
    return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
    ostringstream os("");
    os << a;
    return os.str();
}


template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') {}
    char neg = 0;
    if (ed == '-') {
        neg = 1;
        ed = getchar();
    }
    while (isdigit(ed)) {
        a = 10 * a + ed - '0';
        ed = getchar();
    }
    if (neg) a = -a;
}

template<>
inline void input(string &a) {
    a.clear();
    static int ed;
    while (isspace(ed = getchar())) {}
    while (!isspace(ed) && ed != EOF) {
        a += (char) ed;
        ed = getchar();
    }
}

template<typename T>
inline T nxt() {
    T res;
    input(res);
    return res;
}


bool checkp(long long v) {
    if (v < 2) return false;
    for (long long i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

template<typename T, typename N>
T pw(T a, N n, T m) {
    T res = 1;
    while (n) {
        if (n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

template<typename T>
T inv(T a, T p) {
    T res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}

template<class T>
bool uin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}