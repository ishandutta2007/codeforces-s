#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

int main() {
    //init();
    ll a = 2;
    ll b = 3;
    ll n, c;
    cin >> n;
    for (int i = 1; true; i++) {
        if (n < b) {
            cout << i;
            return 0;
        }
        c = a;
        a = b;
        b += c;
    }
    return 0;
}