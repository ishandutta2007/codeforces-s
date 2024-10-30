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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int mx = 0;
    vector<vector<int>> ret(n, vector<int>(n));

    auto solve = [&] (auto &self, int l, int r, int c) -> void {
        mx = max(mx, c);
        if (r - l < k) {
            for (int i=l; i<r; i++)
                for (int j=i+1; j<=r; j++)
                    ret[i][j] = c;
            return;
        }
        int sz = (r - l + k) / k;
        for (int i=l; i<=r; i+=sz) {
            for (int j=i; j<=min(r, i+sz-1); j++)
                for (int x=i+sz; x<=r; x++)
                    ret[j][x] = c;
            self(self, i, min(r, i + sz - 1), c + 1);
        }
    };

    solve(solve, 0, n - 1, 1);
    cout << mx << "\n";
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            cout << ret[i][j] << " ";
    cout << "\n";

    return 0;
}