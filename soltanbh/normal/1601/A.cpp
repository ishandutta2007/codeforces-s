#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99,lg=31;

int n,t,a[N],b[N],cnt[lg];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		fill(cnt,cnt+lg,0);
		cin>>n;
		f(i,0,n){
			int x;
			cin>>x;
			f(j,0,lg){
				if(x&(1<<j)){
					cnt[j]++;
				}
			}
		}
		vector<int> ans;
		f(i,1,n+1){
			int mv=1;
			f(j,0,lg){
				if(cnt[j]%i!=0)
					mv=0;
			}
			if(mv) cout<<i<<" ";
		}
		cout<<endl;
	}
}