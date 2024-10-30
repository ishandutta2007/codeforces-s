#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int n, m;
set<int> e[MN];
int o[MN];
int p[MN];
int y;
vector<int> bad;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 1, n){
        int x;
        cin >> x;
        o[i] = x;
        p[x] = i;
        if(i == n) y = x;
    }

    F0R(_, m){
        int u, v;
        cin >> u >> v;
        e[u].insert(v);
    }
    //cout << "y is " << y << "\n";

    bad.pb(y);

    RFOR(i, n-1, 1){
        bool good = true;
        F0R(j, bad.size()){
            if(!e[o[i]].count(bad[j])){
                good = false;
                break;
            }
        }
        if(!good){
            bad.pb(o[i]);
            //cout << o[i] << " is bad\n";
        }
    }

    cout << n-bad.size() << "\n";
    
    return 0;
}