//114514min
#include "bits/stdc++.h"
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,i,r=0,rr=1;
		string s,t;
		cin>>n>>s;
		for (i=0;i<n;i+=2) if (s[i]==s[i+1]) t+=s[i]; else ++r;
		for (i=0;i+1<t.size();i++) rr+=t[i]!=t[i+1];
		cout<<r<<' '<<rr<<'\n';
	}
}