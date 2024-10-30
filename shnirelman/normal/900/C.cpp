//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 20000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;

mt19937 rnd(time(0));

/*

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    set<int> st;
    vector<int> res(n, 0);
    for(int i = 0; i < n; i++) {
        if(st.empty() || *st.begin() > -a[i]) {
            res[a[i]]--;
        } else {
            auto it = st.begin();
            it++;

//            cout << i << ' ' << a[i] << ' ' << *st.begin() << endl;

            if(it == st.end() || *it > -a[i]) {
                res[-*st.begin()]++;
            }
        }

        st.insert(-a[i]);
    }

//    for(int i = 0; i < n; i++)
//        cout << res[i] << ' ';

    int mx = 0;
    for(int i = 1; i < n; i++)
        if(res[mx] < res[i])
            mx = i;

    cout << mx + 1 << endl;
}