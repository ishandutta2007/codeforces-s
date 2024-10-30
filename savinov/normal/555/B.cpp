#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

#define next next12345
#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template<class _T>
inline _T sqr(const _T &x) {
    return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
    ostringstream os("");
    os << a;
    return os.str();
}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const long double PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') { }
    char neg = 0;
    if (ed == '-') {
        neg = 1;
        ed = getchar();
    }
    while (isdigit(ed)) {
        a = 10 * a + ed - '0';
        ed = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

mt19937 generator;

long long mod = 1000000123;

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "race"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n = nxt();
    int m = nxt();

    long long l[n], r[n];
    for (int i = 0; i < n; ++i) {
        l[i] = nxt<ll>();
        r[i] = nxt<ll>();
    }
    long long L[n - 1], R[n - 1];

    vector <pair <pair <ll, ll>, int> > z;
    for (int i = 0; i + 1 < n; ++i) {
        L[i] = l[i + 1] - r[i];
        R[i] = r[i + 1] - l[i];
        z.push_back({{L[i], R[i]}, i});
    }

    sort(all(z));

    auto cmp = [&](int u, int v) {
        return R[u] < R[v] || (R[u] == R[v] && u < v);
    };

    set <int, decltype(cmp)> rights(cmp);

    int ans[n - 1];

    pair <long long, int> len[m];
    for (int i = 0; i < m; ++i) {
        len[i].x = nxt<ll>();
        len[i].y = i;
    }
    sort(len, len + m);

    int i = 0, j = 0;

    while (i < z.size() || j < m) {
        if (i < z.size() && j < m) {
            if (len[j].x < z[i].x.x) {
                if (!rights.empty() && R[*rights.begin()] < len[j].x) {
                    cout << "No\n";
                    return 0;
                }
                if (!rights.empty()) {
                    int v = *rights.begin();
                    rights.erase(rights.begin());
                    ans[v] = len[j].y;
                }
                ++j;
            } else {
                rights.insert(z[i].y);
                ++i;
            }
        } else {
            if (i < z.size()) {
                cout << "No\n";
                return 0;
            }
            if (!rights.empty() && R[*rights.begin()] < len[j].x) {
                cout << "No\n";
                return 0;
            }
            if (!rights.empty()) {
                int v = *rights.begin();
                rights.erase(rights.begin());
                ans[v] = len[j].y;
            }
            ++j;
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < n - 1; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}