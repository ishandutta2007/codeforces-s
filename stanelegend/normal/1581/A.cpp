#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL t,n;

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    LL ans=1;
    for(LL i=n+n;i>2;--i) (ans*=i)%=MOD;
    cout<<ans<<endl;
  }
  return 0;
}