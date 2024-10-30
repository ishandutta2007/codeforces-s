//
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
set<int> r[maxn];
int ans = 0;
bool chk(int a) {
    if (r[a].empty()) return 1;
    if (*r[a].rbegin() <= a) return 1;
    return 0;
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        r[u].insert(v), r[v].insert(u);
    }
    int q;
    cin >> q;
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += chk(i);
    for (int i = 1; i <= q; i++) {
        int t, u, v;
        scanf("%d", &t);
        if (t == 3) printf("%d\n", ans);
        else {
            scanf("%d%d", &u, &v);
            ans -= chk(u), ans -= chk(v);
            if (t == 1) r[u].insert(v), r[v].insert(u);
            else r[u].erase(v), r[v].erase(u);
            ans += chk(u), ans += chk(v);
        }
    }
    return (0-0); //<3
}