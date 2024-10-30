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

    string s, t;
    cin >> s >> t;
    int n = (int) s.size();

    sort(s.begin(), s.end());
    sort(t.rbegin(), t.rend());
    s = s.substr(0, (n + 1) / 2);
    t = t.substr(0, n / 2);
    string ret(n, '?');
    int il = 0, ir = (int) s.size() - 1, jl = 0, jr = (int) t.size() - 1, l = 0, r = n - 1;
    for (int k=0; k<n; k++) {
        if (k % 2 == 0) {
            if (s[il] < t[jl])
                ret[l++] = s[il++];
            else
                ret[r--] = s[ir--];
        } else {
            if (t[jl] > s[il])
                ret[l++] = t[jl++];
            else
                ret[r--] = t[jr--];
        }
    }
    cout << ret << "\n";

    return 0;
}