#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int n;string s;
	cin>>n>>s;
	int cnt=0;
	for(auto i:s)if(i=='0')cnt++;
	if(cnt==n-cnt)
    {
        cout<<2<<endl;
        cout<<s.substr(0,s.size()-1)<<' '<<s.back()<<endl;
    }
    else cout<<1<<endl<<s<<endl;
	return 0;
}