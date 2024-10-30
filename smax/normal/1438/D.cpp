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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    int tot = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        tot ^= a[i];
    }

    vector<tuple<int, int, int>> ret;
    if (n % 2 == 0) {
        if (tot != 0) {
            cout << "NO\n";
            return 0;
        }
        ret.emplace_back(0, 1, 2);
        for (int i=3; i+1<n-1; i+=2)
            ret.emplace_back(i-1, i, i+1);
        for (int i=0; i+1<n-2; i+=2)
            ret.emplace_back(i, i+1, n-1);
    } else {
        ret.emplace_back(0, 1, 2);
        for (int i=3; i+1<n; i+=2)
            ret.emplace_back(i-1, i, i+1);
        for (int i=0; i+1<n-1; i+=2)
            ret.emplace_back(i, i+1, n-1);
    }

    assert((int) ret.size() <= n);
    cout << "YES\n" << ret.size() << "\n";
    for (auto [i, j, k] : ret)
        cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";

    return 0;
}