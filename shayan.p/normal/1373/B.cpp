// Never let them see you bleed...
// Shayan.P  2020-06-25

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
	int cnt = 0;
	for(char ch : s){
	    if(ch == '0')
		A++;
	    else
		B++;
	}
	cnt = min(A, B);
	cout << (cnt & 1 ? "DA\n" : "NET\n");
    }
    return 0;
}