#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int T,ans,pos[26];
string s,t;
void solve()
{
	cin>>s>>t;
	for(int i=0;i<26;i++)
		pos[s[i]-'a']=i;
	ans=0;
	for(int i=1;i<t.size();i++)
		ans+=abs(pos[t[i]-'a']-pos[t[i-1]-'a']);
	cout<<ans<<endl;
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}