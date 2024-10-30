#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#include <set>
#include <queue>
#include <list>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef set<p32> ms;
typedef unordered_map<int,int> m32;
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
ll MOD = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi 3.141592653589793238462643383279502884L
#define L 1e9

void f(ll l, ll h){
    if(l==h){
        cout << "! " << l << ln;
        fflush(stdout);
    }
    else if(h-l<2){
        cout << "? " << h << " " << l << ln;
        fflush(stdout);
        string a;
        cin >> a;
        if(a=="y") f(h,h);
        else{
            f(l,l);
        }
    }
    else if(h<2*l){
        ll mid=(l+h)/2;
        cout << "? " << 2*mid << " " << mid << ln;
        fflush(stdout);
        string a;
        cin >> a;
        if(a=="y") f(mid+1,h);
        else{
            f(l,mid);
        }
    }
    else{
        cout << "? " << l-1 << " " << 2*l-1 << ln;
        fflush(stdout);
        string a;
        cin >> a;
        if(a=="y") f(2*l,h);
        else{
            f(l,2*l-1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    // cin.tie(0);
    cout.tie(0);
    string s;
    while(true){
        cin >> s;
        if(s=="start") f(1,L);
        else break;
    }
    return 0;
}