#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, a[N];

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 0; i < n; i++) {
            a[i] = read();
        }
        std::sort(a, a + n);
        std::set<int> set;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            if (set.count(x)) {
                set.insert(x + 1);
            } else {
                set.insert(x);
            }
        }
        printf("%d\n", set.size());
    }

    return 0;
}