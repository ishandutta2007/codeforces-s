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

const int N = 1e3 + 34;

string s;
int w = 3, h = 3;

int main() {
    //init();

    cin >> s;
    int p = 0;
    while (s[p] == 'a') {
        p++;
        if (p == s.length()) {
            s.back() = 'z';
            cout << s;
            return 0;
        }
    }

    while (p < s.length() && s[p] != 'a') {
        s[p++]--;
    }
    cout << s;

    return 0;
}