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

    string s;
    int q;
    cin >> s >> q;
    int n = (int) s.size();

    vector<int> lps(n);
    for (int i=1, j=0; i<n; i++) {
        while (j != 0 && s[i] != s[j])
            j = lps[j-1];
        lps[i] = j += s[i] == s[j];
    }

    vector dp(n, vector<int>(26, -1));
    for (int i=0; i<n; i++) {
        if (i > 0)
            dp[i] = dp[lps[i-1]];
        dp[i][s[i]-'a'] = i;
    }

    for (int i=0; i<q; i++) {
        string t;
        cin >> t;

        int j = lps[n-1];
        for (int k=0; k<(int)t.size(); k++) {
            dp.push_back(dp[j]);
            dp.back()[t[k]-'a'] = n + k;
            j = dp[j][t[k]-'a'] + 1;
            cout << j << " ";
        }
        cout << "\n";
        dp.resize(n);
    }

    return 0;
}