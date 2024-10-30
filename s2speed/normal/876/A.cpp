#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n , a , b , c;
	cin>>n>>a>>b>>c;
	if(n == 1){
		cout<<"0\n";
		return 0;
	}
	n--;
	if(min(a , b) <= c){
		cout<<n * min(a , b)<<'\n';
	} else {
		cout<<min(a , b) + c * (n - 1)<<'\n';
	}
	return 0;
}