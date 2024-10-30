#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int Q = 31;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> cnt(Q, 0);
    for (char c : s) {
        cnt[c - 'A']++;
    }
    int minw = INF;
    for (int i = 0; i < k; i++) {
        minw = min(minw, cnt[i]);
    }
    cout << minw * k;
}