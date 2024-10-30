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
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
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
const int N=5e5+10,M=500;
const ll mod=998244353;

void solve(){
    int n;cin>>n;
    vi ar(n);
    for(auto &i:ar)cin>>i;
    vi cnt(30,0);
    for(auto i:ar){
        for(int j=0;j<30;j++){
            if(i&1<<j)cnt[j]++;
        }
    }
    for(int i=1;i<=n;i++){
        bool ok=1;
        for(auto j:cnt)if(j%i)ok=0;
        if(ok)cout<<i<<' ';
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        solve();
    }
}