#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=505;

int n,t,a[N][N];

int main(){
	cin>>n;
	f(i,1,n+1)
	    cin>>a[i][i];
	f(i,1,n+1){
	    int x=i,y=i;
	    f(j,0,a[i][i]-1){
	        if(a[x][y-1]==0 && y-1)
	            y--;
	        else x++;
	        a[x][y]=a[i][i];
	    }
	}
	f(i,1,n+1){
	    f(j,1,i+1)
	        cout<<a[i][j]<<" ";
	    cout<<endl;
	}
}