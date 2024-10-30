#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int B, K;
    cin >> B >> K;

    int res = 0, dig;
    if (B&1) {
        for (int i = 0; i < K; i++) {
            cin >> dig;
            res += dig&1;
        }
    } else {
        for (int i = 0; i < K; i++) {
            cin >> dig;
            res = dig&1;
        }
    }

    cout << ((res&1) ? "odd" : "even") << endl;

    return 0;
}