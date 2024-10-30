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

const int MOD = 998244353;

int a[200005], b[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<m; i++)
        cin >> b[i];

    reverse(a, a + n);
    reverse(b, b + m);
    int i = 0;
    long long ret = 1;
    for (int j=0; j<m; j++) {
        // find b_j
        while (i < n && a[i] != b[j]) {
            if (a[i] < b[j]) {
                cout << "0\n";
                return 0;
            }
            i++;
        }
        if (i == n) {
            cout << "0\n";
            return 0;
        }

        // find b_{j+1}
        int k = i++;
        if (j == m - 1) {
            while (i < n) {
                if (a[i] < b[j]) {
                    cout << "0\n";
                    return 0;
                }
                i++;
            }
        } else {
            int pos = -1;
            while (i < n && a[i] != b[j+1]) {
                if (a[i] < b[j+1]) {
                    cout << "0\n";
                    return 0;
                }
                if (pos == -1 && a[i] < b[j])
                    pos = i;
                i++;
            }
            if (pos == -1)
                pos = i;
            ret = ret * (pos - k) % MOD;
        }
    }
    cout << ret << "\n";

    return 0;
}