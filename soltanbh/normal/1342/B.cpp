#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,t;
string s;

int main(){
	cin>>t;
	while(t--){
		int p1=0,p2=0;
		cin>>s;
		f(i,0,s.size()){
			if(s[i]=='1') p1=1;
			else p2=1;
		}
		if(p1==0 || p2==0) cout<<s<<endl;
		else{
			f(i,0,s.size())
				cout<<"01";
			cout<<endl;
		}
	}
}