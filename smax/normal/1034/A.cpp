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
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int MAX = 1.5e7 + 5;

int lp[MAX], cnt[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(lp, lp + MAX, 0);
    for (int p=2; p<MAX; p++)
        if (lp[p] == p)
            for (int i=2*p; i<MAX; i+=p)
                lp[i] = p;

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        while (a > 1) {
            int p = lp[a], pw = 1;
            while (a % p == 0) {
                a /= p;
                pw *= p;
                cnt[pw]++;
            }
        }
    }

    int ret = -1;
    for (int p=2; p<MAX; p++)
        if (cnt[p] > 0 && cnt[p] < n)
            ret = max(ret, cnt[p]);
    cout << (ret == -1 ? -1 : n - ret) << "\n";

    return 0;
}