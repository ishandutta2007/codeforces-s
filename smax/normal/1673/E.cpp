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

const int MAX = 1 << 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int i=0; i<n; i++)
        cin >> b[i];

    vector<int> ret(MAX);
    for (int i=0; i<n; i++) {
        int cur = b[i], lim = 0;
        while (cur * 2 < MAX) {
            cur *= 2;
            lim++;
        }
        int j = i, sum = -b[i];
        while (j < n && sum + b[j] <= lim) {
            sum += b[j++];
            int used = (i > 0) + (j < n), left = n - 1 - (j - i - 1 + used);
            if (k - used <= left && (left == 0 || (k > used && ((left - 1) & (k - used - 1)) == k - used - 1)))
                ret[b[i] * (1 << sum)] ^= 1;
        }
    }

    reverse(ret.begin(), ret.end());
    bool start = false;
    for (int x : ret) {
        start |= x == 1;
        if (start) cout << x;
    }
    if (!start) cout << 0;
    cout << "\n";

    return 0;
}