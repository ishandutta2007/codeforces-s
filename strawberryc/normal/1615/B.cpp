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

const int N = 2e5 + 5, E = 21;

int s[N][E];

void yhjssa() {
  int l, r, ans = 0;
  read(l); read(r);
  for (int T = 0; T < 20; T++)
    if (s[r][T] - s[l - 1][T] > ans)
      ans = s[r][T] - s[l - 1][T];
  printf("%d\n", r - l + 1 - ans);
}

int main() {
  for (int i = 1; i <= 200000; i++)
    for (int j = 0; j < 20; j++)
      s[i][j] = s[i - 1][j] + ((i >> j) & 1);
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}