#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int cmp(const void* num1, const void* num2) {
	int a = *(int*)num1;
	int b = *(int*)num2;
	if(a > b) {
		return 1;
	} else if(a < b) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	int h, i, j, k;
	int t, n, m;
	int u, v;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[2*n];
		for(i=0; i<2*n; i++) {
			scanf("%d", &a[i]);
		}
		qsort(a, 2*n, sizeof(int), cmp);
		for(i=0; i<n; i++) {
			printf("%d %d ", a[i], a[n+i]);
		}
		printf("\n");
	}
}