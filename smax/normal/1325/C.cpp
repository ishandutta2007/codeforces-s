#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> degree(n);
    vector<pair<int, int>> edges;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        degree[u]++, degree[v]++;
        edges.emplace_back(u, v);
    }

    vector<pair<int, int>> minDegree(n-1);
    for (int i=0; i<n-1; i++)
        minDegree[i] = {min(degree[edges[i].first], degree[edges[i].second]), i};

    sort(minDegree.begin(), minDegree.end());

    int e = 0;
    vector<int> ret(n-1);
    for (auto p : minDegree)
        ret[p.second] = e++;

    for (int i : ret)
        cout << i << "\n";

    return 0;
}