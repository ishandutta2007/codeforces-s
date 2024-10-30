#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

vector <int> g[sz];
int dis[sz], who[sz];
bool yes, helps[sz];

void dfs(int u, int p, int d) {
   if(d >= dis[u]) {
      helps[who[u]] = 1;
      return;
   }
   for(int v : g[u]) if(v ^ p) dfs(v, u, d + 1);
   if(g[u].size() == 1 and u > 1) yes = 1;
}

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   queue <int> q;
   for(int i=1; i<=n; i++) dis[i] = sz, helps[i] = 0;
   for(int i=0; i<k; i++) {
      int x;
      scanf("%d", &x);
      q.push(x);
      who[x] = i + 1, dis[x] = 0;
   }
   for(int i=1; i<=n; i++) g[i].clear();
   for(int i=1; i<n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
   }
   while(!q.empty()) {
      int u = q.front(); q.pop();
      int d = dis[u] + 1;
      for(int v : g[u]) if(dis[v] > d) {
         q.push(v);
         dis[v] = d;
         who[v] = who[u];
      }
   }
   yes = 0;
   dfs(1, 0, 0);
   if(yes) {
      puts("-1");
      return;
   }

   int cnt = 0;
   for(int i=1; i<=k; i++) cnt += helps[i];
   printf("%d\n", cnt);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}