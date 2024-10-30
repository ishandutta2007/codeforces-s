// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-06

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	if(n <= k)
	    ans = 1;
	k = min(k, n-1);
	ans+= 1ll * k * (k+1) / 2;
	cout << ans << "\n";
    }
    return 0;
}