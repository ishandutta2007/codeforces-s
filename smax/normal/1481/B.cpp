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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        k--;
        vector<int> h(n);
        for (int i=0; i<n; i++)
            cin >> h[i];

        int i = 0;
        while (true) {
            while (i + 1 < n && h[i] >= h[i+1])
                i++;
            if (i == n - 1) {
                cout << "-1\n";
                break;
            }
            int j = i;
            while (j > 0 && h[i] == h[j-1])
                j--;
            int len = i - j + 1, diff = h[i+1] - h[i];
            if (j > 0)
                diff = min(diff, h[j-1] - h[j]);
            DEBUG(j, i, k, h);
            if ((long long) len * diff <= k) {
                for (int x=j; x<=i; x++)
                    h[x] += diff;
                k -= (long long) len * diff;
            } else {
                k %= len;
                cout << i - k + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}