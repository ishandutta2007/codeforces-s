#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007
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
int x; string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> x >> s;
        int ree = 0;
        while(ree <= x-1 && s.length() <= x){
            string rest = s.substr(ree+1);
            F0R(_, s[ree]-'1'){
                s += rest;
            }
            ++ree;
        }
        //cout << ree << " " << s << "\n";
        ll len = s.length();
        FOR(i, ree, x-1){
            ll rest = (len-i-1+MOD)%MOD;
            len = len+rest*(s[i]-'1');
            len %= MOD;
        }
        cout << len << "\n";
    }

    return 0;
}