#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

const ll z = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		for(int i = 0 ; i < s.size() ; i += 2){
			cout<<s[i];
		}
		cout<<s[s.size() - 1]<<"\n";
	}
	return 0;
}