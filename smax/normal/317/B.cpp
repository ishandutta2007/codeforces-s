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

#define MAX 500

int grid[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, t;
    cin >> n >> t;

    grid[MAX][MAX] = n;
    int sz = 0;
    bool done = false;
    while (!done) {
        done = true;
        for (int i=MAX-sz; i<=MAX+sz; i++)
            for (int j=MAX-sz; j<=MAX+sz; j++)
                if (grid[i][j] >= 4) {
                    if (max(abs(i - MAX), abs(j - MAX)) == sz) sz++;
                    done = false;
                    grid[i+1][j] += grid[i][j] / 4;
                    grid[i-1][j] += grid[i][j] / 4;
                    grid[i][j+1] += grid[i][j] / 4;
                    grid[i][j-1] += grid[i][j] / 4;
                    grid[i][j] %= 4;
                }
    }

    while (t--) {
        int x, y;
        cin >> x >> y;
        if (max(abs(x), abs(y)) > sz)
            cout << "0\n";
        else
            cout << grid[x + MAX][y + MAX] << "\n";
    }

    return 0;
}