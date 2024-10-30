#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    vector<string> s;
    int n;
    cin >> n;
    forn (i, n) {
        string t;
        cin >> t;
        bool ok = true;
        forn (j, s.size()) {
            if (s[j] == t) {
                ok = false;
            }
        }
        s.pb(t);
        cout << (ok ? "NO" : "YES") << endl;
    }
    return 0;
}