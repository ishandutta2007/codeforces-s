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

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef int itn;

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

template<typename T>
T pw(T a, T n, T p);

template<typename T>
T inv(T a, T p);

mt19937 gen;

void pre() {
}

struct item {
    ll key;
    int prior;
    int q;
    ll sum;
    item * l, * r;
    item (ll key, int prior) : key(key), prior(prior), q(1), sum(key), l(NULL), r(NULL) { }
};

typedef item * pitem;

ll sum(pitem t) {
    if (t) return t->sum;
    else return 0;
}

int q(pitem t) {
    if (t) return t->q;
    else return 0;
}

void upd(pitem t) {
    if (t) {
        t->sum = t->key + sum(t->l) + sum(t->r);
        if (t->sum > 1.5e18) t->sum = 1.5e18;
        t->q = 1 + q(t->l) + q(t->r);
    }

}

void split (pitem t, ll key, pitem & l, pitem & r) {
    if (!t) l = r = NULL;
    else if (key < t->key)
        split (t->l, key, l, t->l),  r = t;
    else
        split (t->r, key, t->r, r),  l = t;
    upd(t);
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd(t);
}

int find(pitem t, ll need) {
    if (!t) return 0;
    if (sum(t->l) > need) {
        return find(t->l, need);
    }
    if (sum(t->l) + t->key <= need) {
        return q(t->l) + 1 + find(t->r, need - (sum(t->l) + t->key));
    }
    return q(t->l);
}

void solve(int test) {
    int n = nxt();
    pair <ll, ll> t[n];
    forn(i, n) {
        t[i].x = nxt();
        t[i].y = nxt();
    }
    sort(t + 1, t + n, greater <pair <ll, ll> >());

    pitem root = 0;

    int ans = n;

    int q = 0;

    for (int i = 1; i < n; ++i) {
        if (t[i].x <= t[0].x) {
            ll have = t[0].x - t[i].x;
            ans = min(ans, i - find(root, have));
        }
        pitem l, r;
        ll delta = t[i].y - t[i].x + 1;
        split(root, delta, l, r);

        pitem e = new item(delta, gen());

        merge(root, l, e);
        merge(root, root, r);
    }

    ans = min(ans, n - find(root, t[0].x));

    cout << ans << "\n";
}


int main(int argc, char **argv) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
#define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    pre();
    int t = 1;
#ifdef LOCAL
#else
#endif
    for (int test = 1; test <= t; ++test) {
        solve(test);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}


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

template<typename T = long long>
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

bool checkp(long long v) {
    if (v < 2) return false;
    for (long long i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

template<typename T>
T pw(T a, T n, T m) {
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