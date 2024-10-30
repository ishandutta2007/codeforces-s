#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <functional>
#include <ctime>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
#include <iomanip>
#include <float.h>
#include <math.h>
using namespace std;
using ll = long long;


unsigned euclidean_gcd(unsigned a, unsigned b) {
    if (a < b) return euclidean_gcd(b, a);
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

class UnionFind {
public:
    vector <ll> par;
    vector <ll> siz;
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    ll root(ll x) {
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    ll size(ll x) {
        return siz[root(x)];
    }
};

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}


int main() {
    int t;
    cin >> t;
    vector<int> oans(t,-1);
    vector<int> tans(t,-1);
    vector<int> alp(447);
    int now = 0;
    for (int i = 2; i < 3164; i++) {
        ll flag = 0;
        for (int j = 2; j < min(60, i); j++) {
            if (i % j == 0)flag = 1;
        }
        if (flag == 0) {
            alp[now] = i;
            now++;
        }

    }
    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        int za = a;
        for (int j = 0; j < 447; j++) {
            while (za % alp[j] == 0) {
                za /= alp[j];
            }
            if (za != a) {
                if (za == 1)break;
                oans[i] = za;
                tans[i] = a / za;
                break;
            }
        }
    }
    for (int j = 0; j < t; j++) {
        cout << oans[j] << " ";
    }
    cout << endl;
    for (int j = 0; j < t; j++) {
        cout << tans[j] << " ";
    }
    cout << endl;
}