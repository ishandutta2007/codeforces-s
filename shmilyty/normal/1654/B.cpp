#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
int t,num[26];
void solve()
{
	string s;
	cin>>s;
	memset(num,0,sizeof(num));
	for(int i=0;i<s.size();i++)
		num[s[i]-'a']++;
	for(int i=0;i<s.size();i++)
		if(num[s[i]-'a']==1)
		{
			cout<<s.substr(i,s.size()-i)<<'\n';
			return ;
		}
		else
			num[s[i]-'a']--;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}