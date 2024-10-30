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
        string s;
        cin >> n >> s;

        vector<int> last(10, -1);
        for (int i=0; i<n; i++)
            last[s[i]-'0'] = i;

        for (int d=0; d<10; d++) {
            string ret(n, '-');
            int last1 = -1, last2 = -1, mx = *max_element(last.begin(), last.begin() + d);
            bool ok = true;
            for (int i=0; i<n; i++) {
                int e = s[i] - '0';
                if (e < d || (e == d && i > mx && e >= last1)) {
                    if (e < last1) {
                        ok = false;
                        break;
                    }
                    ret[i] = '1';
                    last1 = e;
                } else {
                    if (e < last2) {
                        ok = false;
                        break;
                    }
                    ret[i] = '2';
                    last2 = e;
                }
            }
            if (ok) {
                cout << ret << "\n";
                goto done;
            }
        }
        cout << "-\n";
        done:;
    }

    return 0;
}