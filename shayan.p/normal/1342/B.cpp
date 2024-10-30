// Never let them see you bleed...
// Shayan.P  2020-04-26

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
	string s;
	cin >> s;
	int A = 0, B = 0;
	for(char c : s){
	    (c == '0' ? A : B)++;
	}
	if(A == 0 || B == 0)
	    cout << s << "\n";
	else{
	    for(int i = 0; i < sz(s); i++)
		cout << "01";
	    cout << "\n";
	}
    }
    return 0;
}