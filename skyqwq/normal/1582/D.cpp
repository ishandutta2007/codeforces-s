// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int n, a[N], b[N];
 
int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]), b[i] = 0;
        for (int i = 1; i + 1 <= n; i += 2) {
            b[i] += -a[i + 1];
            b[i + 1] += a[i];
        }
        if (n & 1) {
            b[1] += -a[n], b[n] += a[1];
            if (b[1] == 0) b[1] += -a[n], b[n] += a[1];
        }
        for (int i = 1; i <= n; i++) printf("%d ", b[i]); puts("");
    }
    return 0;
}