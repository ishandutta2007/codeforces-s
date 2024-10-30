#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN     "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<')';Err(x...);}
template<template<class...> class T,class t,class...A>void Err(T<t>a,A...x){cerr<<a.size()<<":{";for(auto v:a)Err(v);cerr<<"}";Err(x...);}
typedef long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
//#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#endif
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=100+10,M=400;
const ll mod=998244353;

//void solve(){
//    int n,m;cin>>n>>m;
//    set<int>s;
//    for(int i=0;i<m;i++){
//        int a,b,c;cin>>a>>b>>c;
//        s.insert(b);
//    }
//    int o;
//    for(int i=1;i<=n;i++)if(!s.count(i))o=i;
//    for(int i=1;i<=n;i++){
//        if(i!=o)cout<<o<<" "<<i<<endl;
//    }
//}
int pre[N],nxt[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"? ";
        for(int j=1;j<=n;j++)cout<<(j==i)+1<<' ';
        cout<<endl;
        int id;cin>>id;
        if(id&&id!=i)nxt[i]=id,pre[id]=i;

        cout<<"? ";
        for(int j=1;j<=n;j++)cout<<(j!=i)+1<<' ';
        cout<<endl;
        cin>>id;
        if(id&&id!=i)nxt[id]=i,pre[i]=id;
    }
    int ans[N]{};
    for(int i=1;i<=n;i++)if(!pre[i]){
        int tot=0;
        while(i){
            ans[i]=++tot;
            i=nxt[i];
        }
        break;
    }
    cout<<"! ";
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    cout<<endl;
}