#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int n, k, a[200000];

bool check(int x, bool odd) {
    int cntOdd = 0, cntEven = 0, len = 0;
    for (int i=0; i<n; i++) {
        if (len % 2) {
            if (odd || a[i] <= x) {
                cntEven++;
                len++;
            }
        } else {
            if (!odd || a[i] <= x) {
                cntOdd++;
                len++;
            }
        }
    }
    return len >= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> a[i];

    int l = 0, r = 1e9;
    while (l < r) {
        int m = (l + r) / 2;
        if (check(m, false) || check(m, true))
            r = m;
        else
            l = m + 1;
    }

    cout << l << "\n";

    return 0;
}