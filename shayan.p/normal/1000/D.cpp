// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1010;
const ll mod=998244353;

ll dp[maxn][maxn];

int main(){
    ll n;cin>>n;
    dp[0][0]=1;
    FOR(i,1,n){
	ll x;cin>>x;
	FOR(j,0,n){
	    dp[i][j]=(dp[i-1][j]+dp[i-1][j+1])%mod;
	}
	if(0<x&&x<=n) dp[i][x]=(dp[i][x]+dp[i-1][0])%mod;
    }
    cout<<(dp[n][0]-1+mod)%mod;
}