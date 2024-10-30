#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <double, double> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

template <int nmax, int emax, typename T> struct graph {
    struct edge {
        int v, u, c, f;
        T w;
        edge () { f = 0; };
        edge (int v, int u, int c, T w) : v(v), u(u), c(c), f(0), w(w) {};
    };

    edge e[emax * 2];
    vector<int> g[nmax];
    int s, t, m;

    graph () : m(0) {};

    inline void init() {
        forn(i, nmax)
            g[i].clear();
        m = 0;
    }

    inline void add(int v, int u, int c, T w) {
        e[m] = edge(v, u, c, w);
        e[m^1] = edge(u, v, 0, -w);
        g[v].pb(m);
        g[u].pb(m^1);
        m += 2;
    }

    queue<int> q;
    bitset<nmax> inq, used;
    T dst[nmax];
    int p[nmax];

    inline void put(int v, T cur, int pred) {
        if (used[v] && dst[v] <= cur) return;
        if (!inq[v]) q.push(v);
        dst[v] = cur; 
        p[v] = pred;
        used[v] = inq[v] = 1;
    }

    bool singleSearch() {
        inq.reset();
        used.reset();
        put(s, 0, -1);
        while (!q.empty()) {
            int v = q.front();
            q.pop(); inq[v] = 0;
            T now = dst[v];
            forn(i, g[v].size()) {
                int id = g[v][i];
                if (e[id].c - e[id].f > 0) 
                    put(e[id].u, now + e[id].w, id);
            }
        }
        return used[t];
    }

    T updatePath() {
        int now = t;
        while (now != s) {
            int id = p[now];
            e[id].f ++;
            e[id^1].f --;
            now = e[id].v;
        }
        return dst[t];
    }

    T minCostFlow() {
        T res = 0;
        while (singleSearch() && dst[t] <= 0) res += updatePath();
        return res;
    }

    T minCostMaxFlow() {
        T res = 0;
        while (singleSearch()) res += updatePath();
        return res;
    }
};

const int nmax = 7000;

int px[] = {-1, 0, 1, 0};
int py[] = {0, -1, 0, 1};

int a[100][100];
int n, m;
graph<nmax, nmax * 100, int> G;

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> m;
    forn(i, n)
        forn(j, m)
            cin >> a[i][j];
    G.s = n * m;
    G.t = n * m + 1;
    forn(i, n)
        forn(j, m) {
            int v = i * m + j;
            if ((i + j) % 2 == 0)
                G.add(G.s, v, 1, 0);
            else
                G.add(v, G.t, 1, 0);
            if ((i + j) % 2 != 0) continue;
            forn(k, 4) {
                int nx = i + px[k];
                int ny = j + py[k];
                if (nx < 0 || ny < 0 || nx == n || ny == m) continue;
                int u = nx * m + ny;
                if (a[i][j] == a[nx][ny]) {
                    G.add(v, u, 1, 0);
//                  cerr << v << " " << u << endl;
//                  g[v].pb(u);
                } else
                    G.add(v, u, 1, 1);
            }
        }   
    int res = G.minCostMaxFlow();
    cout << res << endl;


    return 0;
}