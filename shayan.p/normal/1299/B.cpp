// So when you feel like hope is gone, Look inside you and be strong, And you'll finally see the truth, That a hero lies in you ... 
 
#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> p){
    out << "{ " << p.F << ", " << p.S <<" }";
    return out;
}
template<typename T> ostream& operator << (ostream& out, vector<T> v){
    out << "[ ";
    for(int i = 0; i < sz(v); i++){
	out << v[i];
	if(i != sz(v)-1)
	    out << " ,";
    }
    out << " ]";
    return out;
}

pll p[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	cin >> p[i].F >> p[i].S;
    }
    if(n & 1)
	return cout << "NO\n", 0;
    int N = n/2;
    for(int i = 0; i < N; i++){
	pll A = p[i], B = p[i+1], C = p[i+N], D = p[(i+N+1) %n];
	if(A.F - B.F + C.F - D.F != 0 || A.S - B.S + C.S - D.S != 0)
	    return cout << "NO\n", 0;
    }
    return cout << "YES\n", 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")