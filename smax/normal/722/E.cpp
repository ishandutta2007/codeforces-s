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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
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
    friend ostream& operator << (ostream &os, const ModInt &m) {return os << m.v;}
};
typedef ModInt<1000000007> M;

const int MAX = 2e5 + 5;

M fact[MAX], inv[MAX];

M choose(int n, int k) {
    if (k < 0 || n < k) return 0;
    return fact[n] * inv[k] * inv[n-k];
}

void preprocess() {
    fact[0] = 1;
    for (int i=1; i<MAX; i++)
        fact[i] = fact[i-1] * i;
    inv[MAX-1] = inverse(fact[MAX-1]);
    for (int i=MAX-2; i>=0; i--)
        inv[i] = inv[i+1] * (i + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    preprocess();

    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<pair<int, int>> a(k);
    for (int i=0; i<k; i++)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end());
    if (!a.empty() && a[0] == make_pair(1, 1)) {
        s = (s + 1) / 2;
        a.erase(a.begin());
        k--;
    }
    if (!a.empty() && a.back() == make_pair(n, m)) {
        s = (s + 1) / 2;
    } else {
        a.emplace_back(n, m);
        k++;
    }

    vector<int> values{s};
    while (values.back() > 1)
        values.push_back((values.back() + 1) / 2);
    int o = (int) values.size();

    auto ways = [&] (const pair<int, int> &p, const pair<int, int> &q) -> M {
        if (p.first > q.first || p.second > q.second)
            return 0;
        return choose(q.first - p.first + q.second - p.second, q.first - p.first);
    };

    vector<vector<M>> dp(k, vector<M>(o));
    for (int i=0; i<k; i++) {
        dp[i][0] = ways({1, 1}, a[i]);
        for (int j=0; j<i; j++)
            dp[i][0] -= dp[j][0] * ways(a[j], a[i]);
    }
    for (int i=0; i<k; i++)
        for (int l=1; l<o; l++) {
            dp[i][l] = ways({1, 1}, a[i]) - accumulate(dp[i].begin(), dp[i].begin() + l, M(0));
            for (int j=0; j<i; j++)
                dp[i][l] -= dp[j][l] * ways(a[j], a[i]);
        }

    M ret = ways({1, 1}, {n, m}) - accumulate(dp[k-1].begin(), dp[k-1].end(), M(0));
    for (int l=0; l<o; l++)
        ret += dp[k-1][l] * values[l];
    cout << ret / ways({1, 1}, {n, m}) << "\n";

    return 0;
}