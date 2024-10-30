#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

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

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        if (m == 1) {
            cout << n << "\n";
            continue;
        }

        vector<M> pref(n + 1);
        for (int i=0; i<=n; i++)
            pref[i] = choose(i, m - 2) + (i > 0 ? pref[i-1] : 0);

        M ret = 0;
        sort(a.begin(), a.end());
        for (int i=0, j=0; i<n; i++) {
            while (j < i && a[i] - a[j] > k)
                j++;
            if (j < i)
                ret += pref[i-j-1];
        }
        cout << ret << "\n";
    }

    return 0;
}