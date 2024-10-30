#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define bit_exist(x, n) ((x >> n) & 1)
#define Ans(f, y, n) if(f) cout << y << endl; else cout << n << endl;
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) cout << #v << "=" << endl; REP(i, v.size()){ cout << v[i] << ","; } cout << endl;
#define mdebug(m) cout << #m << "=" << endl; REP(i, m.size()){ REP(j, m[i].size()){ cout << m[i][j] << ","; } cout << endl;}
#define pb push_back
#define f first
#define s second
#define int long long
#define INF 1000000000000000000

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;
using pairs = vector<Pii>;

template<typename T> void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readv_m1(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};

int mod = 1000000007;
//int mod = 998244353;
#define Add(x, y) x = (x + (y)) % mod
#define Mult(x, y) x = (x * (y)) % mod



signed main(){

    int n; cin >> n;
    vec s(n); readv(s);
    Sort(s);
    map<int, int> mnum, msum;
    vec v;
    REP(i, n - 1){
        mnum[s[i + 1] - s[i]] += 1;
        msum[s[i + 1] - s[i]] += s[i + 1] - s[i];
    }
    int tmp1 = 0, tmp2 = 0;
    for(auto &p: mnum){
        tmp1 += p.s;
        p.s = tmp1;
    }
    for(auto &p: msum){
        tmp2 += p.s;
        p.s = tmp2;
    }

    int q; cin >> q;
    int l, r;
    vec ans(q);
    REP(i, q){
        cin >> l >> r;
        int d = r - l;
        auto it = mnum.upper_bound(d);
        if(it == mnum.begin()){
            ans[i] = n * (d + 1);
        }else{
            it--;
            int k = it -> f;
            ans[i] = (n - mnum[k]) * (d + 1) + msum[k];
        }
    }
    REP(i, q) cout << ans[i] << " ";
    cout << endl;

    return 0;
}