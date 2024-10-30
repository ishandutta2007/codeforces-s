#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct Node {
    int mx, mn, lazy = 0, l, r;

    void leaf(int val) {
        mx = mn = val;
    }

    void pull(const Node &a, const Node &b) {
        mx = max(a.mx, b.mx);
        mn = min(a.mn, b.mn);
    }

    void push(int val) {
        lazy += val;
    }

    void apply() {
        mx += lazy;
        mn += lazy;
        lazy = 0;
    }
};

struct SegmentTree {
    int n;
    vector<int> a;
    vector<Node> st;

    SegmentTree(int _n) : n(_n), a(n), st(4*n) {
        build(1, 0, n-1);
    }

    SegmentTree(const vector<int> &_a) : n((int) _a.size()), a(_a), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        st[p].l = l;
        st[p].r = r;
        if (l == r) {
            st[p].leaf(a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void push(int p) {
        if (st[p].lazy) {
            if (st[p].l != st[p].r) {
                st[2*p].push(st[p].lazy);
                st[2*p+1].push(st[p].lazy);
            }
            st[p].apply();
        }
    }

    Node query(int p, int i, int j) {
        push(p);
        if (st[p].l == i && st[p].r == j)
            return st[p];
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m)
            return query(2*p, i, j);
        else if (i > m)
            return query(2*p+1, i, j);
        Node ret, ls = query(2*p, i, m), rs = query(2*p+1, m+1, j);
        ret.pull(ls, rs);
        return ret;
    }

    Node query(int i, int j) {
        return query(1, i, j);
    }

    void update(int p, int i, int j, int val) {
        if (st[p].l == i && st[p].r == j) {
            st[p].push(val);
            push(p);
            return;
        }
        push(p);
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m) {
            update(2*p, i, j, val);
            push(2*p+1);
        } else if (i > m) {
            push(2*p);
            update(2*p+1, i, j, val);
        } else {
            update(2*p, i, m, val);
            update(2*p+1, m+1, j, val);
        }
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, int val) {
        update(1, i, j, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());

    // i is to the left of the median
    vector<int> pref(n + 1), ret(n + 1);
    iota(pref.begin(), pref.end(), 0);
    SegmentTree st1(pref);
    for (int i=0; i<n; ) {
        int j = i;
        while (j < n && a[i].first == a[j].first) {
            ret[a[j].second] = max(ret[a[j].second], (st1.query(a[j].second, n).mx - st1.query(0, a[j].second - 1).mn) / 2);
            j++;
        }
        for (int k=i; k<j; k++)
            st1.update(a[k].second, n, -2);
        i = j;
    }

    // i is to the right of the median
    for (int i=1; i<=n; i++)
        pref[i] = pref[i-1] - 1;
    SegmentTree st2(pref);
    for (int i=0; i<n; ) {
        int j = i;
        while (j < n && a[i].first == a[j].first)
            st2.update(a[j++].second, n, 2);
        for (int k=i; k<j; k++)
            ret[a[k].second] = max(ret[a[k].second], (st2.query(a[k].second, n).mx - st2.query(0, a[k].second - 1).mn - 1) / 2);
        i = j;
    }

    for (int i=1; i<=n; i++)
        cout << ret[i] << " ";
    cout << "\n";

    return 0;
}