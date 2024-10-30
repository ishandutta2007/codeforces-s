#include <bits/stdc++.h>

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

const int N = 1e5 + 5;

int n, a[N];

void yhjssa() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  int cnt = 0;
  for (int i = 1; i <= n; i++) if (a[i] && !a[i - 1]) cnt++;
  printf("%d\n", std::min(cnt, 2));
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}