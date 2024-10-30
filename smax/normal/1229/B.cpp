#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

template<int MOD>
struct ModInt {
    long long v;
    ModInt(long long _v = 0) {v = (-MOD < _v && _v < MOD) ? _v : _v % MOD; if (v < 0) v += MOD;}
    ModInt& operator += (const ModInt &other) {v += other.v; if (v >= MOD) v -= MOD; return *this;}
    ModInt& operator -= (const ModInt &other) {v -= other.v; if (v < 0) v += MOD; return *this;}
    ModInt& operator *= (const ModInt &other) {v = v * other.v % MOD; return *this;}
    ModInt& operator /= (const ModInt &other) {return *this *= inverse(other);}
    bool operator == (const ModInt &other) const {return v == other.v;}
    bool operator != (const ModInt &other) const {return v != other.v;}
    friend ModInt operator + (ModInt a, const ModInt &b) {return a += b;}
    friend ModInt operator - (ModInt a, const ModInt &b) {return a -= b;}
    friend ModInt operator * (ModInt a, const ModInt &b) {return a *= b;}
    friend ModInt operator / (ModInt a, const ModInt &b) {return a /= b;}
    friend ModInt operator - (const ModInt &a) {return 0 - a;}
    friend ModInt power(ModInt a, long long b) {ModInt ret(1); while (b > 0) {if (b & 1) ret *= a; a *= a; b >>= 1;} return ret;}
    friend ModInt inverse(ModInt a) {return power(a, MOD - 2);}
    friend istream& operator >> (istream &is, ModInt &m) {is >> m.v; m.v = (-MOD < m.v && m.v < MOD) ? m.v : m.v % MOD; if (m.v < 0) m.v += MOD; return is;}
    friend ostream& operator << (ostream &os, const ModInt &m) {return os << m.v;}
};
typedef ModInt<1000000007> M;

const int LOG = 17;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> x(n + 1);
    for (int i=1; i<=n; i++)
        cin >> x[i];
    vector<vector<int>> adj(n + 1);
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<int>> up(n + 1, vector<int>(LOG));
    vector<vector<long long>> g(n + 1, vector<long long>(LOG));
    g[1][0] = x[1];

    auto dfs = [&] (auto &self, int u) -> void {
        for (int v : adj[u])
            if (v != up[u][0]) {
                up[v][0] = u;
                g[v][0] = __gcd(x[u], x[v]);
                self(self, v);
            }
    };

    dfs(dfs, 1);
    for (int j=1; j<LOG; j++)
        for (int i=0; i<=n; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
            g[i][j] = __gcd(g[i][j-1], g[up[i][j-1]][j-1]);
        }

    M ret = 0;
    for (int i=1; i<=n; i++) {
        int u = i;
        long long cur = x[u];
        while (u != 0) {
            for (int j=LOG-1; j>=0; j--)
                if (up[u][j] != 0 && ((cur == 0 && g[u][j] == 0) || (cur != 0 && g[u][j] % cur == 0))) {
                    ret += M(cur) * (1 << j);
                    u = up[u][j];
                    DEBUG(i, u, j);
                }
            DEBUG(i, u, ret, cur, g[u][0], up[u][0]);
            ret += cur;
            cur = __gcd(cur, g[u][0]);
            u = up[u][0];
        }
        DEBUG(i, u, ret);
    }
    cout << ret << "\n";

    return 0;
}