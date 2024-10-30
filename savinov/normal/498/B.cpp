#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define in(x) int (x); input((x));
#define x first
#define y second
#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)
#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))

using namespace std;

template <typename T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

typedef long double ld; typedef unsigned int uint; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR;

typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(long long a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    //string name = "cheval";
    //freopen((name + ".in").c_str(), "r", stdin);
    //freopen((name + ".out").c_str(), "w", stdout);
#endif

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms.\n";
#endif // LOCAL
    in(n); in(T);

    double P[T + 1][n + 1];
    clr(P);

    P[0][0] = 1;

    double p[n];

    int t[n];

    for (int i = 0; i < n; ++i) {
        p[i] = nxt() / 100.0;
        t[i] = nxt();
    }

    double Q[n];

    for (int i = 0; i < n; ++i) {
        Q[i] = 1;
        for (int j = 0; j + 1 < t[i]; ++j) {
            Q[i] *= 1 - p[i];
        }
    }

    double dp[n + 1];
    clr(dp);
    double tmp[n + 1];
    dp[0] = 1;
    for (int tt = 0; tt < T; ++tt) {
        clr(tmp);
        for (int i = 0; i < n; ++i) {
            double p1 = (tt + 1 >= t[i]) ? P[tt + 1 - t[i]][i] : 0;
            double q1 = 1 - p1;
            double pp = p1 * Q[i] + (dp[i] - p1 * Q[i]) * p[i];
            //cerr << pp << " ";
            double qq = (dp[i] - p1 * Q[i]) * (1 - p[i]);
            P[tt + 1][i + 1] = pp;
            tmp[i] += qq;
            tmp[i + 1] += pp;
        }
        //cerr << endl;
        tmp[n] += dp[n];
        memcpy(dp, tmp, sizeof(dp));
    }

    double ans = 0;

    for (int i = 0; i <= n; ++i) {
        ans += dp[i] * i;
    }
    cout << setprecision(10) << fixed;
    cout << ans << "\n";

    return 0;
}