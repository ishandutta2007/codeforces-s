#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &k);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		int answer = 0;
		for(i=0; i<k; i++) {
			if(a[n-1-i] == a[n-1-i-k]) {
				answer++;
			}
		}
		for(i=0; i<n-2*k; i++) {
			answer += a[i];
		}
		printf("%d\n", answer);
	}
}