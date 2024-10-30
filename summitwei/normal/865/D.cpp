#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int n;
int p[MN];
multiset<pii> ms;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ans = 0;

    cin >> n;
    F0R(i, n){
        cin >> p[i];
        ans += p[i];
    }

    F0R(i, n){
        ms.insert(mp(p[i], true));

        pii f = *ms.begin();
        ms.erase(ms.begin());
        if(f.s) ms.insert(mp(f.f, false));
        ans -= f.f;
    }

    cout << ans << "\n";

    return 0;
}