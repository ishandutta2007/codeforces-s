#pragma GCC optimize("O3")

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ld INFLD = 1e20;
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(123876);

double ReadDouble() {
    string s;
    cin >> s;
    return stol(s);
}

namespace AhoCorasick {
    const int MAXN = 1000100;
    const int ALPH = 26;

    int size;
    int h[MAXN], root[MAXN], char_ind[MAXN], prev[MAXN], prev_str[MAXN], is_str[MAXN];
    int next[MAXN][ALPH];

    void AddNode(int ch, int c_root, int char_i) {
        h[size] = ch;
        root[size] = c_root;
        char_ind[size] = char_i;
        prev[size] = 0;
        prev_str[size] = 0;
        is_str[size] = -1;
        for (int i = 0; i < ALPH; ++i) {
            next[size][i] = -1;
        }
        ++size;
    }

    void Init() {
        size = 0;
        AddNode(0, 0, 0);
    }

    void AddString(const string& s, int string_ind) {
        int cn = 0;
        for (char c : s) {
            if (next[cn][c - 'a'] == -1) {
                AddNode(h[cn] + 1, cn, c - 'a');
                next[cn][c - 'a'] = size - 1;
            }
            cn = next[cn][c - 'a'];
        }
        is_str[cn] = string_ind;
    }

    void ConstructAho() {
        queue<int> que;
        // Insert all root's children into queue
        for (int i = 0; i < ALPH; ++i) {
            if (next[0][i] == -1) {
                next[0][i] = 0;
            }
            else {
                que.push(next[0][i]);
            }
        }

        // Go through the nodes with BFS, set their 'prev', 'prev_string' and 'next' values
        while (!que.empty()) {
            int cn = que.front();
            que.pop();
            prev[cn] = next[prev[root[cn]]][char_ind[cn]];
            if (prev[cn] == cn) {
                prev[cn] = 0;
            }
            if (is_str[prev[cn]] >= 0) {
                prev_str[cn] = prev[cn];
            }
            else {
                prev_str[cn] = prev_str[prev[cn]];
            }
            for (int i = 0; i < ALPH; ++i) {
                if (next[cn][i] == -1) {
                    next[cn][i] = next[prev[cn]][i];
                }
                else {
                    que.push(next[cn][i]);
                }
            }
        }
    }
};

vector<int> Prefix(string s) {
    int n = s.length();
    vector<int> pr(n);
    for (int i = 1; i < n; i++) {
        int j = pr[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pr[j - 1];
        if (s[i] == s[j])
            j++;
        pr[i] = j;
    }
    return pr;
}

int LCP(int ci, int cj, const vector<vector<int>>& c, int n, int log_n) {
    int ans = 0;
    for (int k = log_n; k >= 0; --k) {
        //assert(k < c.size());
        assert(ci < c[k].size());
        assert(cj < c[k].size());
        if (c[k][ci] == c[k][cj]) {
            ans += (1 << k);
            ci += (1 << k);
            cj += (1 << k);
        }
    }
    return ans;
}

void Solve() {
    string s;
    cin >> s;
    int tot_k;
    cin >> tot_k;

    int n = s.size() + 1;
    s += ('z' + 1);
    int alph = 'z' - 'a' + 2;

    if ((ll)n * ((ll)n - 1) / 2 < (ll)tot_k) {
        cout << "No such line.\n";
        return;
    }

    // phase 0
    vector<int> p(n, 0), cnt(alph, 0);
    vector<vector<int>> c(25, vector<int>(n));

    for (int i = 0; i < n; ++i)
        ++cnt[s[i] - 'a'];

    for (int i = 1; i < alph; ++i)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; ++i)
        p[--cnt[s[i] - 'a']] = i;

    c[0][p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; ++i) {
        if (s[p[i]] != s[p[i - 1]])  ++classes;
        c[0][p[i]] = classes - 1;
    }

    // phase 1
    vector<int> pn(n), cn(n);
    int log_n{ 0 };
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; ++i) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)  pn[i] += n;
        }
        cnt.assign(classes, 0);
        for (int i = 0; i < n; ++i)
            ++cnt[c[h][pn[i]]];
        for (int i = 1; i < classes; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i)
            p[--cnt[c[h][pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; ++i) {
            int mid1 = (p[i] + (1 << h)) % n, mid2 = (p[i - 1] + (1 << h)) % n;
            if (c[h][p[i]] != c[h][p[i - 1]] || c[h][mid1] != c[h][mid2])
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c[h + 1] = cn;
        log_n = h + 1;
    }

    int ci = 0, ni = 0, cl = 1;
    //for (int i = 0; i < n; ++i) {
    //    cerr << p[i] << ", ";
    //} cerr << "\n";
    //cerr << LCP(0, 1, c, n, log_n) << ", " << LCP(0, 2, c, n, log_n) << "\n";
    while (tot_k > 0) {
        //cerr << tot_k << ", " << ci << ", " << cl << "\n";
        assert(ci < p.size());
        ni = ci;
        if (p[ci] + cl > n - 1) {
            ++ci;
            cl = LCP(p[ci], p[ci - 1], c, n, log_n) + 1;
            continue;
        }
        --tot_k;
        //cerr << tot_k << ", " << s.substr(p[ci], cl) << "\n";
        while (LCP(p[ci], p[ni + 1], c, n, log_n) >= cl && tot_k > 0) {
            --tot_k;
            ++ni;
            //cerr << "step...\n";
            assert(ni + 1 < p.size());
        }
        if (tot_k > 0) {
            ++cl;
            ni = ci;
        }
    }
    //while (p[ci] + cl > n - 1) {
    //    ++ci;
    //    cl = LCP(ci, ci - 1, c, n, log_n) + 1;
    //}

    cout << s.substr(p[ci], cl) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL

    int t = 1;
    //cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}