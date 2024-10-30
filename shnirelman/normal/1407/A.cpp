#include <bits/stdc++.h>

#define f first
#define s second
#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 998244353;//1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    return (a + b) % M;
//    a += b;
//    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    if(k % 2)
        return mul(pw, n);
    else
        return pw;
}
/*
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> c(2, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        c[a[i]]++;
    }

    int mx = (c[0] >= c[1] ? 0 : 1);

    if(mx == 1 && c[1] % 2 != 0)
        c[1]--;

    cout << c[mx] << endl;
    for(int i = 0; i < c[mx]; i++)
        cout << mx << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}