#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN    "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<')';Err(x...);}
template<template<class...> class T,class t,class...A>void Err(T<t>a,A...x){cerr<<a.size()<<":{";for(auto v:a)Err(v);cerr<<"},";Err(x...);}
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(b<a)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
//#define endl '\n'
#define F(x){x;}
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#define F(x)
#endif
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=1e5+10,M=200+10;
const ll mod=1e9+97;

ll ask(ll a){
    cout<<"? "<<a<<endl;
    cin>>a;
    return a;
}
vi prm;
void solve(){
    ll A=1e18,B=1e9;
    vl v;
    for(int i=0,j=0;i<17;i++){
        ll a=1,l=j;
        while(a<=A/prm[j]){
            a*=prm[j];
            j++;
        }
        a=ask(a);
        while(l!=j){
            if(a%prm[l]==0)v.push_back(prm[l]);
            l++;
        }
    }
    vl vv(v);
    for(int i=0;i<v.size();i++){
        while(vv[i]<=B/v[i])vv[i]*=v[i];
    }
    ll ans=1;
    for(int i=0;i<v.size();i+=2){
        ll a=ask(vv[i]*(i+1<v.size()?vv[i+1]:1));
        ll cnt=1;
        while(a%v[i]==0)cnt++,a/=v[i];
        ans*=cnt;
        cnt=1;
        while(i+1<v.size()&&a%v[i+1]==0)cnt++,a/=v[i+1];
        ans*=cnt;
    }
    cout<<"! "<<(ans<=7?ans+7:ans*2)<<endl;
}
bool vis[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    for(int i=2;i*i<N;i++)if(!vis[i])
        for(int j=i*i;j<N;j+=i)vis[j]=1;
    for(int i=2;i<N;i++)if(!vis[i])prm.push_back(i);
    int _;cin>>_;
    while(_--){
        solve();
    }
}