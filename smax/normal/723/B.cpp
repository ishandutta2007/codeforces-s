// Problem : B. Text Document Analysis
// Contest : Codeforces - Codeforces Round #375 (Div. 2)
// URL : https://codeforces.com/problemset/problem/723/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n;
    string s;
    cin >> n >> s;
    
    int i = 0, mx = 0, cnt = 0;
    bool inside = false;
    while (i < n) {
        while (i < n && (s[i] == '_' || s[i] == '(' || s[i] == ')')) {
            if (s[i] == '(')
                inside = true;
            else if (s[i] == ')')
                inside = false;
            i++;
        }
        
        int start = i;
        while (i < n && s[i] != '_' && s[i] != '(' && s[i] != ')')
            i++;
        
        if (inside)
            cnt++;
        else
            mx = max(mx, i - start);
    }
    
    cout << mx << " " << cnt << "\n";

    return 0;
}