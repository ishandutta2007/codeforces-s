#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>

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
typedef unordered_map<int,int> m32;
typedef map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
typedef pair<ll,p64 > pp64;
ll MOD = 1e9 + 7;
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
#define INF LLONG_MAX


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    ll n;
    cin >> n;
    cin >> s;
    if(n%2 != 0){
        cout << ":(" << ln;
        return 0;
    }
    ll req = n/2;
    forn(i,n){
        if(s[i]=='(') req--;
    }
    ll ans=0;
    forn(i,n){
        if(s[i]=='?'){
            if(req > 0) {s[i]='('; req--;}
            else s[i]=')';
        }
        if(s[i]=='(') ans++;
        else ans--;
        if(ans<=0 && i!=n-1){
            cout << ":(" << ln;
            return 0;
        }
    }
    if(ans!=0){
        cout << ":(" << ln;
        return 0;
    }
    cout << s << ln;
    return 0;
}