#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 3e5 + 10;

int n, m;
int p[MAXN];
int rp[MAXN];
int nxt[MAXN];

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        rp[p[i]] = i;
        nxt[i] = n;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        a = rp[a];
        b = rp[b];
        if (a > b) swap(a, b);
        chkmin(nxt[a], b);
    }
}

ll ans;

void run() {
    ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        chkmin(nxt[i], nxt[i + 1]);
    }

    for (int i = 0; i < n; i++) {
        ans += nxt[i] - i;
    }
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}