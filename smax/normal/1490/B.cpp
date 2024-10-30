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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cnt(3);
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            cnt[a % 3]++;
        }

        int ret = INT_MAX;
        for (int rep=0; rep<3; rep++) {
            DEBUG(rep, cnt);
            if (cnt[0] <= n / 3) {
                if (cnt[2] <= n / 3) {
                    ret = min(ret, (n / 3 - cnt[0]) * 2 + n / 3 - cnt[2]);
                } else {
                    int change = min(n / 3 - cnt[0], cnt[2]), n0 = cnt[0] + change, n2 = cnt[2] - change;
                    ret = min(ret, (n / 3 - n0) * 2 + (n2 < n / 3 ? n / 3 - n2 : 2 * (n / 3 - cnt[1])) + change);
                }
            }
            rotate(cnt.begin(), cnt.begin() + 1, cnt.end());
        }
        cout << ret << "\n";
    }

    return 0;
}