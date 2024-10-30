#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN     "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<')';Err(x...);}
template<template<class...> class T,class t,class...A>void Err(T<t>a,A...x){cerr<<a.size()<<":{";for(auto v:a)Err(v);cerr<<"}";Err(x...);}
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid ((l+r)/2)
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
const int N=400+10,M=500;
const ll mod=1e9+7;
const double eps=1e-8;
double sgn(double x){return x<=-eps?-1:(x<eps?0:1);}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    auto solve=[&](){
        int n;cin>>n;
        string s;cin>>s;
        vector<string>ans(n,string(n,'='));
        for(int i=0;i<n;i++)ans[i][i]='X';
        vi v;
        for(int i=0;i<n;i++){
            if(s[i]=='2'){
                v.push_back(i);
            }
        }
        if(v.size()==1||v.size()==2){cout<<"NO"<<endl;return;}
        cout<<"YES"<<endl;
        for(int i=0;i<v.size();i++){
            int a=v[i],b=v[(i+1)%v.size()];
            ans[a][b]='+';
            ans[b][a]='-';
        }
        for(int i=0;i<n;i++)cout<<ans[i]<<endl;
    };
    int _;cin>>_;
    while(_--){
        solve();
    }
}