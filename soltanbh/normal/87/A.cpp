#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

ll n,a,b,ans1,ans2,g;

int main(){
	cin>>a>>b;
	g=__gcd(a,b);
	ans1=b/g;
	ans2=a/g;
	if(ans1<ans2)
		ans1++;
	if(ans2<ans1)
		ans2++;
	if(ans1>ans2)
		cout<<"Dasha";
	if(ans2>ans1)
		cout<<"Masha";
	if(ans1==ans2)
		cout<<"Equal";
}