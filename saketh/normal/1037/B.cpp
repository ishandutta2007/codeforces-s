#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, S;
    cin >> N >> S;

    vi vals(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
    }
    sort(all(vals));

    ll ans = 0;
    if (vals[N/2] == S) {
        // do nothing
    } else if (vals[N/2] < S) {
        for (int i = N/2; i < N; i++) {
            ans += max(0, S - vals[i]);
        }
    } else {
        for (int i = 0; i <= N/2; i++) {
            ans += max(0, vals[i] - S);
        }
    }

    cout << ans << endl;
    return 0;
}