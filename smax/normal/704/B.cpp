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

const long long INF = 1e14;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s, e;
    cin >> n >> s >> e;
    s--, e--;
    vector<int> x(n), a(n), b(n), c(n), d(n);
    for (int i=0; i<n; i++)
        cin >> x[i];
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        cin >> b[i];
    for (int i=0; i<n; i++)
        cin >> c[i];
    for (int i=0; i<n; i++)
        cin >> d[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));
    dp[0][0] = 0;
    for (int i=0; i<n; i++) {
        long long diff = i + 1 < n ? x[i+1] - x[i] : INF;
        for (int j=0; j<=i; j++) {
            if (i == s) {
                // must go on left end
                // create new component
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + d[i] + diff * (2 * (j + 1) - (s <= i) - (e <= i)));
                // join with existing component
                if (j - (i + 1 < n && e <= i) > 0)
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j] + c[i] + diff * (2 * j - (s <= i) - (e <= i)));
            } else if (i == e) {
                // must go on right end
                // create new component
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + b[i] + diff * (2 * (j + 1) - (s <= i) - (e <= i)));
                // join with existing component
                if (j - (i + 1 < n && s <= i) > 0)
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[i] + diff * (2 * j - (s <= i) - (e <= i)));
            } else {
                // create new component
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + b[i] + d[i] + diff * (2 * (j + 1) - (s <= i) - (e <= i)));
                // append on left of component
                if (j - (s <= i) > 0)
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j] + b[i] + c[i] + diff * (2 * j - (s <= i) - (e <= i)));
                // append on right of component
                if (j - (e <= i) > 0)
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[i] + d[i] + diff * (2 * j - (s <= i) - (e <= i)));
                // merge two components together
                if (j >= 3 || (j == 2 && !(i + 1 < n && s <= i && e <= i)))
                    dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j] + a[i] + c[i] + diff * (2 * (j - 1) - (s <= i) - (e <= i)));
            }
        }
    }
    cout << dp[n][1] << "\n";

    return 0;
}