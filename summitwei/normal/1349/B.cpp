#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int t;
int n, k;
int a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n >> k;
        FOR(i, 1, n) cin >> a[i];
        bool app = false, cons = false;
        if(n == 1) cons = true;
        FOR(i, 1, n){
            if(a[i] == k) app = true;
            if(i < n && a[i] >= k && a[i+1] >= k) cons = true;
            if(i > 1 && i < n && a[i-1] >= k && a[i+1] >= k) cons = true;
        }
        if(app && cons) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}