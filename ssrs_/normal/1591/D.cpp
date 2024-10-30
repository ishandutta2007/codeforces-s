#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T sum(int L, int R){
    return sum(R) - sum(L);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    binary_indexed_tree<int> BIT(n);
    long long S = 0;
    for (int j = 0; j < n; j++){
      S += BIT.sum(a[j] + 1, n);
      BIT.add(a[j], 1);
    }
    if (S % 2 == 0){
      cout << "YES" << "\n";
    } else {
      sort(a.begin(), a.end());
      bool ok = false;
      for (int j = 0; j < n - 1; j++){
        if (a[j] == a[j + 1]){
          ok = true;
        }
      }
      if (ok){
        cout << "YES" << "\n";
      } else {
        cout << "NO" << "\n";
      }
    }
  }
}