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

long long f[222][3222],x;
int n,s,t;
char a[222];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d\n",&t);
	f[0][0]=1;
	for (int i=0;i<107;i++)for (int j=0;j<=i*26;j++)for (int l=0;l<='z'-'a';l++)f[i+1][j+l]=(f[i+1][j+l]+f[i][j])%M;
	while (t--){
		gets(a);
		n=strlen(a);
		s=0;
		for (int i=0;i<n;i++)s+=a[i]-'a';
		x=(f[n][s]-1+M)%M;
		CC(x);
	}
	return 0;
}