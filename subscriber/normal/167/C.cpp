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

long long t,a,b;

bool gg(long long x,long long y){
	y--;
	if (x%2)return y%2;
	y%=x+1;
	return y==x||y%2;
}


bool rec(long long a,long long b){
	if (a>b)swap(a,b);
	if (!a)return 0;
	if (!rec(a,b%a))return 1;
	return gg(a,b/a);
}


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> t;
	while (t--){
		cin >> a >> b;
		if (rec(a,b))puts("First");else puts("Second");
	}
	return 0;
}