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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> p(n);
        for (int i=0; i<n; i++)
            cin >> p[i];

        long long ret = 0, sum = 0;
        for (int i=1; i<n; i++) {
            // p_i / (p_0 + p_1 + ... + p_{i-1}) <= k / 100
            // p_i * 100 <= (p_0 + p_1 + ... + p_{i-1}) * k
            // ceil(p_i * 100 / k) <= p_0 + p_1 + ... + p_{i-1}
            sum += p[i-1];
            ret += max((p[i] * 100LL + k - 1) / k - sum - ret, 0LL);
        }
        cout << ret << "\n";
    }

    return 0;
}