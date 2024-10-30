#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rng(98);

struct node {
    int x, y, c;
    ll s;
    node *l, *r;

    node(int x) : x(x), y(rng()), l(nullptr), r(nullptr) {
        c = 1;
        s = x;
    }

    void recalc();
};

int cnt(node *n) { return n ? n->c : 0; }
ll sum(node *n) { return n ? n->s : 0; }
void node::recalc() {
    c = cnt(l) + cnt(r) + 1;
    s = sum(l) + sum(r) + x;
}

pair<node*, node*> split(node* t, int x) {
    if(!t)
        return {nullptr, nullptr};
    if(t->x > x) {
        auto p = split(t->l, x);
        t->l = p.second;
        t->recalc();
        return {p.first, t};
    }
    auto p = split(t->r, x);
    t->r = p.first;
    t->recalc();
    return {t, p.second};
}

node* insert(node* t, node* n) {
    if(!t)
        return n;
    if(n->y >= t->y) {
        if(n->x <= t->x) {
            t->l = insert(t->l, n);
            t->recalc();
        }
        else {
            t->r = insert(t->r, n);
            t->recalc();
        }
        return t;
    }
    auto p = split(t, n->x);
    n->l = p.first;
    n->r = p.second;
    n->recalc();
    return n;
}

ll prf(node *t, int p) {
    if(!t)
        return 0;
    if(cnt(t) < p)
        return -1;
    if(p <= cnt(t->l))
        return prf(t->l, p);
    return sum(t->l) + t->x + prf(t->r, p - cnt(t->l) - 1);
}

const int MAXN = 2e5 + 10;
int val[MAXN], msk[MAXN], n, m, k;
vector<int> byt[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    int a;
    cin >> a;
    while(a--) {
        int x;
        cin >> x;
        msk[x]++;
    }
    cin >> a;
    while(a--) {
        int x;
        cin >> x;
        msk[x] += 2;
    }
    for(int i = 1; i <= n; i++)
        byt[msk[i]].push_back(val[i]);
    for(int i = 0; i < 4; i++)
        sort(byt[i].begin(), byt[i].end());
    node *t = nullptr;
    for(auto x : byt[0])
        t = insert(t, new node(x));
    ll curs = 0, ans = -1, s1 = 0, s2 = 0;
    for(int i = 0; i < min(k + 1, (int)byt[1].size()); i++)
        s1 += byt[1][i];
    for(int i = 0; i < min(k + 1, (int)byt[2].size()); i++)
        s2 += byt[2][i];
    for(int i = k + 1; i < byt[1].size(); i++)
        t = insert(t, new node(byt[1][i]));
    for(int i = k + 1; i < byt[2].size(); i++)
        t = insert(t, new node(byt[2][i]));
    for(int both = 0; both <= byt[3].size(); both++) {
        int oth = max(k - both, -1);
        if(both)
            curs += byt[3][both - 1];
        if(oth >= 0 && oth < byt[1].size()) {
            s1 -= byt[1][oth];
            t = insert(t, new node(byt[1][oth]));
        }
        if(oth >= 0 && oth < byt[2].size()) {
            s2 -= byt[2][oth];
            t = insert(t, new node(byt[2][oth]));
        }
        oth = max(oth, 0);
        if(oth > byt[1].size() || oth > byt[2].size() || both + 2*oth > m || m - both - 2*oth > cnt(t))
            continue;
        int rem = m - both - 2*oth;
        ll x = curs + s1 + s2 + prf(t, rem);
        if(ans == -1)
            ans = x;
        else
            ans = min(ans, x);
    }
    cout << ans << '\n';
}