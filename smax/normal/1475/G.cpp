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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());
        vector<int> dp(n), last(200005, -1);
        int ret = n - 1;
        dp[0] = 0;
        last[a[0]] = 0;
        for (int i=1; i<n; i++) {
            dp[i] = i;
            for (int j=1; j*j<=a[i]; j++)
                if (a[i] % j == 0)
                    for (int x : {j, a[i] / j})
                        if (last[x] != -1)
                            dp[i] = min(dp[i], dp[last[x]] + i - last[x] - 1);
            last[a[i]] = i;
            ret = min(ret, dp[i] + n - i - 1);
        }
        cout << ret << "\n";
    }

    return 0;
}