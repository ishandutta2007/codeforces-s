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
    vec a(n); readv(a);
    int m = 0, i = 0, j = n - 1;
    string ans;
    while(i <= j && max(a[i], a[j]) > m){
        if(a[i] == a[j]){
            //l to r
            int m0 = m;
            string ans1 = "";
            FOR(k, i, j + 1){
                if(a[k] > m){
                    ans1 += 'L';
                    m = a[k];
                }else break;
            }
            string ans2 = "";
            m = m0;
            IFOR(k, i, j + 1){
                if(a[k] > m){
                    ans2 += 'R';
                    m = a[k];
                }else break;
            }
            if(SZ(ans1) >= SZ(ans2)) ans += ans1;
            else ans += ans2;
            break;
        }else if(m < a[i] && (a[i] <= a[j] || a[j] <= m)){
            ans += 'L';
            m = a[i];
            i++;
        }else{
            ans += 'R';
            m = a[j];
            j--;
        }
    }
    cout << SZ(ans) << endl;
    cout << ans << endl;

    return 0;
}