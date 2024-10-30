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

#define MN 70005
int n;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    ll sm = 0;
    F0R(i, n){
        int x = s[i]-'0';
        if(x%2 == 0){
            sm += i+1;
        }
    }

    cout << sm << "\n";
    
    return 0;
}