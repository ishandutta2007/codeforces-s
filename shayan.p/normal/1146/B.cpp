// Faster!

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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

string A,B,ans;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    int num=0;
    for(int i=0;i<sz(s);i++)
	num+=s[i]!='a';
    if(num&1) return cout<<":(\n",0;
    num>>=1;
    int pos=0;
    while(pos<sz(s) && num>0){
	num-=(s[pos]!='a');
	if(s[pos]!='a') A+=s[pos];
	ans+=s[pos],pos++;
    }
    while(pos<sz(s) && s[pos]=='a')
	pos++,ans+='a';
    for(int i=pos;i<sz(s);i++){
	if(s[i]=='a') return cout<<":(\n",0;
	B+=s[i];
    }
    if(A==B) return cout<<ans<<endl,0;
    return cout<<":(\n",0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.