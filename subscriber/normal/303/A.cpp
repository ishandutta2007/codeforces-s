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
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	int n;
	cin >> n;
	if (n%2==0){
		puts("-1");
		return 0;
	}
	for (int i=0;i<n;i++)printf("%d ",i);
	puts("");
	for (int i=0;i<n;i++)printf("%d ",(i+1)%n);
	puts("");
	for (int i=0;i<n;i++)printf("%d ",(i+1+i)%n);
	puts("");
	return 0;
}