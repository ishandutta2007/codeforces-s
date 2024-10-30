#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e16;
const ll INF = 1e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void repl(int i, int j, vector<int>& ax, vector<int>& ay, vector<string>& s) {
    ax.push_back(i);
    ay.push_back(j);
    s[i][j] = '0' + (1 - (s[i][j] - '0'));
}

void dia(int i, int j, vector<int>& ax, vector<int>& ay, vector<string>& s) {
    if (s[i][j] == '1') {
        repl(i, j, ax, ay, s);
        repl(i + 1, j, ax, ay, s);
        repl(i, j + 1, ax, ay, s);
    }
}

void dow(int i, int j, vector<int>& ax, vector<int>& ay, vector<string>& s) {
    if (s[i][j] == '1' && s[i][j + 1] == '1') {
        repl(i, j, ax, ay, s);
        repl(i + 1, j, ax, ay, s);
        repl(i, j + 1, ax, ay, s);
    }
    else if (s[i][j] == '1') {
        repl(i, j, ax, ay, s);
        repl(i + 1, j, ax, ay, s);
        repl(i + 1, j + 1, ax, ay, s);
    }
    else if (s[i][j + 1] == '1') {
        repl(i, j + 1, ax, ay, s);
        repl(i + 1, j, ax, ay, s);
        repl(i + 1, j + 1, ax, ay, s);
    }
}

void rig(int i, int j, vector<int>& ax, vector<int>& ay, vector<string>& s) {
    if (s[i][j] == '1' && s[i + 1][j] == '1') {
        repl(i, j, ax, ay, s);
        repl(i + 1, j, ax, ay, s);
        repl(i, j + 1, ax, ay, s);
    }
    else if (s[i][j] == '1') {
        repl(i, j, ax, ay, s);
        repl(i, j + 1, ax, ay, s);
        repl(i + 1, j + 1, ax, ay, s);
    }
    else if (s[i + 1][j] == '1') {
        repl(i + 1, j, ax, ay, s);
        repl(i, j + 1, ax, ay, s);
        repl(i + 1, j + 1, ax, ay, s);
    }
}

void up(int cx, int cy, vector<int>& ax, vector<int>& ay, vector<string>& s) {
    vector<int> x1, y1, x0, y0;
    for (int i = cx; i < cx + 2; ++i) {
        for (int j = cy; j < cy + 2; ++j) {
            if (s[i][j] == '1') {
                x1.push_back(i);
                y1.push_back(j);
            }
            else {
                x0.push_back(i);
                y0.push_back(j);
            }
        }
    }
    if (x1.size() == 3) {
        for (int i = 0; i < x1.size(); ++i) {
            ax.push_back(x1[i]);
            ay.push_back(y1[i]);
            s[x1[i]][y1[i]] = '0';
        }
    }
    else if (x1.size() == 4) {
        for (int i = 0; i < 3; ++i) {
            ax.push_back(x1[i]);
            ay.push_back(y1[i]);
            s[x1[i]][y1[i]] = '0';
        }
        up(cx, cy, ax, ay, s);
    }
    else if (x1.size() != 0) {
        for (int i = 0; i < 1; ++i) {
            ax.push_back(x1[i]);
            ay.push_back(y1[i]);
            s[x1[i]][y1[i]] = '0';
        }
        for (int i = 0; i < 2; ++i) {
            ax.push_back(x0[i]);
            ay.push_back(y0[i]);
            s[x0[i]][y0[i]] = '1';
        }
        up(cx, cy, ax, ay, s);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> ax, ay;
    
    for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < m - 2; ++j) {
            dia(i, j, ax, ay, s);
        }
    }

    for (int i = 0; i < n - 2; ++i) {
        dow(i, m - 2, ax, ay, s);
    }

    for (int j = 0; j < m - 2; ++j) {
        rig(n - 2, j, ax, ay, s);
    }

    up(n - 2, m - 2, ax, ay, s);

    cout << ax.size() / 3 << "\n";
    for (int i = 0; i < ax.size(); i += 3) {
        for (int j = 0; j < 3; ++j) {
            cout << ax[i + j] + 1 << " " << ay[i + j] + 1 << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}