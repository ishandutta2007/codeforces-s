#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

string s,ss;
int ans=1e9;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> s >> ss;
	for (int i=0;i<ss.size();i++)s='+'+s;
	for (int i=0;i<ss.size();i++)s=s+'+';
	for (int i=0;i+ss.size()<=s.size();i++){
		int t=0;
		for (int j=0;j<ss.size();j++)t+=ss[j]!=s[i+j];
		ans=min(ans,t);
	}
	CC(ans);
	return 0;
}