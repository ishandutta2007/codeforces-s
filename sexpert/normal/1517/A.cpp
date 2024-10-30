#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        if(x % 2050) {
            cout << "-1\n";
            continue;
        }
        x /= 2050;
        ll ans = 0;
        while(x) {
            ans += (x % 10);
            x /= 10;
        }
        cout << ans << '\n';
    }
}