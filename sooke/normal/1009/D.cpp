#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define lol long long

inline int read() {
	char c = getchar();
	int n = 0, f = 0;
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = 1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar();
	}
	return f ? -n : n;
}

#define MAXN 100005

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int n, m, e, u[MAXN], v[MAXN];

int main() {
	n = read(), m = read();
	if (m < n - 1) {
		printf("Impossible\n");
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		u[++e] = 1, v[e] = i;
	}
	for (int i = 2; i <= n && e < m; i++) {
		for (int j = 2; j <= i && e < m; j++) {
			if (gcd(i, j) == 1) {
				u[++e] = i, v[e] = j;
			}
		}
	}
	if (e == m) {
		printf("Possible\n");
		for (int i = 1; i <= e; i++) {
			printf("%d %d\n", u[i], v[i]);
		}
	} else {
		printf("Impossible\n");
	}
	return 0;
}

// By Sooke.
// CF1009D Relatively Prime Graph.