#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int t, n, m, res, bit[N][N], a[N * N], b[N * N];

int query(int x) {
    int i = (x + m - 1) / m;
    x -= (i-1) * m;
    int val = 0;
    for(; x; x-=x&-x) val += bit[i][x];
    return val;
}

void update(int x) {
    int i = (x + m - 1) / m;
    x -= (i-1) * m;
    for(; x<=m; x+=x&-x) ++bit[i][x];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for(int i=1; i<=n*m; ++i) cin >> a[i], b[i] = i;

        sort(b+1, b+n*m+1, [] (int A, int B) { return a[A] < a[B] || a[A] == a[B] && A < B; });
        for(int i=1, cnt=0; i<=n*m; ++i) {
            int j = i;
            while (j < n*m && a[b[i]] == a[b[j+1]]) a[++j];
            int mid = (i + m - 1) / m * m, mid2 = (j - 1) / m * m;
            if (j <= mid) {
                for(int w=j; w>=i; --w) a[b[w]] = ++cnt;
            }
            else {
                for(int w=mid; w>=i; --w) a[b[w]] = ++cnt;
                for(int w=mid2; w>mid; --w) a[b[w]] = ++cnt;
                for(int w=j; w>mid2; --w) a[b[w]] = ++cnt;
            }
            i = j;
        }

        for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) bit[i][j] = 0;
        res = 0;
        for(int i=1; i<=n*m; ++i) {
            res += query(a[i]);
            update(a[i]);
        }
        cout << res << '\n';
    }
}