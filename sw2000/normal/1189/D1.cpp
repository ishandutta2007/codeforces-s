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
int du[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
    {
        int u,v;cin>>u>>v;
        du[u]++;
        du[v]++;
    }
    for(int i=1;i<=n;i++)if(du[i]==2)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
	return 0;
}