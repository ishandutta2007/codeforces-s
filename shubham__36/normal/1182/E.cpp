#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF LLONG_MAX/2e5

#define REP(i,n) for (ll i = 1; i <= n; i++)
typedef vector<vector<ll> > matrix;
const ll K = 3;
matrix C(K+1, vector<ll>(K+1));
// matrix Y(K+1, vector<ll>(K+1));

void mul(matrix& A, matrix& B)
{
	REP(i, K) REP(j, K) C[i][j]=0;
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % (MOD-1);
}

void pow(matrix& A, ll p)
{
    if (p == 1)
        return;
    if (p % 2){
    	matrix Y(K+1, vector<ll>(K+1));
    	Y = A;
    	pow(A,p-1);
    	mul(A,Y);
    	A = C;
    	return;
    }
    pow(A, p/2);
    mul(A,A);
    A = C;
    return;
}



ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

void solve(){
	ll n,f1,f2,f3,c;
	cin >> n >> f1 >> f2 >> f3 >> c;
	matrix T(K+1, vector<ll>(K+1));
	T[1][1] = 1, T[1][2] = 1, T[1][3]=1;
	T[2][1] = 1, T[2][2] = 0, T[2][3]=0;
	T[3][1] = 0, T[3][2] = 1, T[3][3]=0;
	pow(T, n-3);
	ll g1 = (f1*c)%MOD;
	ll g2 = (f2*mpow(c,2))%MOD;
	ll g3 = (f3*mpow(c,3))%MOD;
	ll p1=T[1][3],p2=T[1][2],p3=T[1][1];
	ll ans = ((mpow(g1,p1)*mpow(g2,p2)%MOD)*mpow(g3,p3)%MOD);
	ll p = n%(MOD-1);
	if(p!=0) p = MOD-1-p;
	ans *= mpow(c,p);
	ans %= MOD;
	cout << ans << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}