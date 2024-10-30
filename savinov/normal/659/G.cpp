#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

//#define next next12345
//#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const ld PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') { }
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

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

void myassert(bool v) {
    assert(v);
    //cout << "FAIL\n";
    //exit(0);
}

mt19937 generator;

bool check(int v) {
    if (v < 2) return false;
    for (int i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

long long pw(long long a, long long n, long long m) {
    ll res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

long long mod = 1000000007;

int sz;

long long data[1 << 20];

void add(int v, long long value) {
    for (; v < sz; v |= v + 1) {
        data[v] += value;
        if (data[v] >= mod) {
            data[v] -= mod;
        }
    }
}

long long get(int v) {
    long long res = 0;
    for (; v >= 0; v &= v + 1, --v) {
        res += data[v];
    }
    return res % mod;
}

void solve(int test) {
    int n = nxt();

    int h[n];

    for (int i = 0; i < n; ++i) {
        h[i] = nxt() - 1;
    }

    long long ans = 0;

    long long dp[n][2];
    clr(dp);

    for (int i = 0; i < n; ++i) {
        if (i + 1 < n) {
            dp[i][0] = min(h[i + 1], h[i]);
            if (i) {
                int tx = min(h[i], min(h[i - 1], h[i + 1]));
                dp[i][1] = tx * (dp[i - 1][0] + dp[i - 1][1]) % mod;
            }
        }
        if (i) ans += min(h[i - 1], h[i]) * (dp[i - 1][0] + dp[i - 1][1]) % mod;
        ans += h[i];
    }
    ans %= mod;
    cout << ans << "\n";
}



int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
#ifdef LOCAL

    int t = 1;
#else
    int t = 1;
#endif
    int c = 0;
    while (t--) {
        solve(++c);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}