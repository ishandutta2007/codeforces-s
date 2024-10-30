#include <cstdio>

const int MAXN = 1 << 17;
const int SIZE = MAXN << 1;
const int MOD = 1E9;

typedef long long ll;

int A[MAXN];
int B[MAXN];
ll scalA[MAXN];
ll scalB[MAXN];

void prec() {
	A[0] = 1;
	B[0] = 0;
	for(int i = 0; i + 1 < MAXN; ++i) {
		A[i + 1] = (A[i] + B[i]) % MOD;
		B[i + 1] = A[i];
	}

	scalA[0] = 1;
	scalB[1] = 1;

	for(int i = 0; i + 2 < MAXN; ++i) {
		ll &cur = scalA[i + 2];
		cur = (scalA[i] - scalA[i + 1]) % MOD;
		if (cur < 0) cur += MOD;
	}

	for(int i = 0; i + 2 < MAXN; ++i) {
		ll &cur = scalB[i + 2];
		cur = (scalB[i] - scalB[i + 1]) % MOD;
		if (cur < 0) cur += MOD;
	}
}

struct node {
	int a;
	int b;
	int c;
	node() {
		a = b = c = 0;
	}
};

node operator+(node x, node y) {
	node z;
	z.a = (x.a + y.a) % MOD;
	z.b = (x.b + y.b) % MOD;
	z.c = (x.c + y.c) % MOD;
	return z;
}

node seg[SIZE];
node zero;
void set(int idx, int val, int cur = 1, int l = 0, int r = MAXN) {
	if (l + 1 == r) {
		if (l == idx) {
			node &n = seg[cur];
			ll diff = (val - n.c) % MOD;
			if (diff < 0) diff += MOD;

			(n.c += diff) %= MOD;
			(n.b += diff * B[idx] % MOD) %= MOD;
			(n.a += diff * A[idx] % MOD) %= MOD;
		}
	} else {
		int mid = (l + r) / 2;
		int childl = cur * 2, childr = childl + 1;
		if (mid > idx) set(idx, val, childl, l, mid);
		else set(idx, val, childr, mid, r);
		seg[cur] = seg[childl] + seg[childr];
	}
}

node query(int left, int right, int cur = 1, int l = 0, int r = MAXN) {
	int childl = cur * 2, childr = childl + 1;
	int mid = (l + r) / 2;

	if (left <= l && r <= right) {
		return seg[cur];
	} else if (left >= r || l >= right) {
		return zero;
	} else {
		node n1 = query(left, right, childl, l, mid);
		node n2 = query(left, right, childr, mid, r);
		return n1 + n2;
	}
}

int N, Q;

int main() {
	prec();
	scanf("%d %d", &N, &Q);

	for(int i = 1; i <= N; ++i) {
		int nxt;
		scanf("%d", &nxt);
		set(i, nxt);
	}

	for(int q = 0; q < Q; ++q) {
		int qtype;
		scanf("%d", &qtype);
		if (qtype == 1) {
			int x, v;
			scanf("%d %d", &x, &v);
			set(x, v);
		} else if (qtype == 2) {
			int l, r;
			scanf("%d %d", &l, &r);
			node n = query(l, r + 1);

			int ans = (n.a * scalA[l] + n.b * scalB[l]) % MOD;
			printf("%d\n", ans);
		}
	}
	return 0;
}