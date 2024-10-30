//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

template <class T>
V<T> make_vec(size_t a) {
    return V<T>(a);
}

template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T>
void mkuni(vector<T>& v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
}

template <class T>
vector<int> sort_by(const vector<T>& v) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) { return v[i] < v[j]; });
    return res;
}

template <class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
    is >> p.first >> p.second;
    return is;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) {
        is >> x;
    }
    return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

template <class T>
void scan(vector<T>& v, T offset = T(0)) {
    for (auto& x : v) {
        cin >> x;
        x += offset;
    }
}

template <class T>
void print(T x, int suc = 1) {
    cout << x;
    if (suc == 1)
        cout << "\n";
    else if (suc == 2)
        cout << " ";
}

template <class T>
void print(const vector<T>& v, int suc = 1) {
    for (int i = 0; i < v.size(); ++i)
        print(v[i], i == int(v.size()) - 1 ? suc : 2);
}

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;

V<pii> rec(int n) {
    V<pii> res;
    if (n <= 2) return res;
    int p = 1;
    while (p * 2 <= n) p *= 2;
    if (n == p) {
        return rec(n - 1);
    }

    res = rec(p * 2 - n - 1);
    for (int x = p + 1; x <= n; ++x) {
        res.eb(x, p * 2 - x);
    }

    auto vr = rec(n - p);
    for (auto& [a, b] : vr) {
        a *= 2;
        b *= 2;
    }
    for (auto p : vr) res.pb(p);
    return res;
}

void slv() {
    int n;
    cin >> n;
    if (n == 2) {
        print(-1);
        return;
    }
    auto vec = rec(n);
    debug(vec);

    int x = 1;
    while (x < n) x *= 2;
    map<int, int> T;
    rep(i, n) T[i + 1]++;

    auto ch = [&](int x, int y) {
        T[x]--;
        T[y]--;
        T[x + y]++;
        T[abs(x - y)]++;
    };

    for (auto p : vec) {
        int x = p.fi, y = p.se;
        ch(x, y);
    }

    for (auto& [v, c] : T) {
        if (v != 0 && v < x && c >= 2) {
            vec.eb(v, v);
            ch(v, v);
            break;
        }
    }

    for (auto [v, c] : T) {
        if (v != 0) {
            rep(k, c) {
                int cur = v;
                while (cur < x) {
                    vec.eb(cur, 0);
                    vec.eb(cur, cur);
                    ch(cur, 0);
                    ch(cur, cur);
                    cur *= 2;
                }
            }
        }
    }

    int c = T[0];
    rep(i, c) {
        vec.eb(0, x);
        ch(0, x);
    }

    print(SZ(vec));
    for (auto p : vec) {
        cout << p.fi << ' ' << p.se << '\n';
    }

    {
        for (auto [p, q] : T) {
            if (q > 0) {
                debug(p);
            }
        }
    }
}

int main() {
    int cases = 1;
    cin >> cases;
    rep(i, cases) slv();

    return 0;
}