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

const int N=1e5+2;

int n,a[N],dp[N],ans=1;
set<pair<int,int> > s;

int main(){
    cin>>n;
    f(i,1,n+1) cin>>a[i];
    f(i,1,N) dp[i]=-1;
    f(i,0,N) s.insert(mp(dp[i],i));
    f(i,2,n+1)
        if(a[i]!=a[i-1]){
            ans++;
            int res=0;
            pair<int,int> p1;
            p1=*s.rbegin();
            res=p1.F;
            if(dp[a[i]]==p1.F) res++;
            s.erase(mp(dp[a[i-1]],a[i-1]));
            dp[a[i-1]]=res;
            s.insert(mp(dp[a[i-1]],a[i-1]));
        }
    cout<<ans-(*s.rbegin()).F;
}