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
        vector<int> u(n);
        vector<vector<int>> group(n);
        for (int i=0; i<n; i++) {
            cin >> u[i];
            u[i]--;
        }
        for (int i=0; i<n; i++) {
            int s;
            cin >> s;
            group[u[i]].push_back(s);
        }

        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        sort(perm.begin(), perm.end(), [&] (int a, int b) -> bool {
            if (group[a].size() == group[b].size()) return a < b;
            return group[a].size() > group[b].size();
        });

        vector<vector<long long>> pref(n, {0});
        for (int i=0; i<n; i++) {
            sort(group[i].rbegin(), group[i].rend());
            for (int x : group[i])
                pref[i].push_back(pref[i].back() + x);
        }

        for (int k=1; k<=n; k++) {
            long long ret = 0;
            for (int i : perm) {
                if ((int) group[i].size() < k)
                    break;
                for (int j=k; j<=(int)group[i].size(); j+=k)
                    ret += pref[i][j] - pref[i][j-k];
                i++;
            }
            cout << ret << " ";
        }
        cout << "\n";
    }

    return 0;
}