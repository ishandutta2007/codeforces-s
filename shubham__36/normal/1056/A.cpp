#include <bits/stdc++.h>
#include <set>
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
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
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
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    m32 v1;
    m32 v2;
    int r;
    cin >> r;
    int k;
    forn(i,r){
        cin >> k;
        v1[k]=1;
    }
    forn(i,n-1){
        cin >> r;
        forn(j,r){
            cin >> k;
            if(i%2 == 0 && v1.find(k)!= v1.end()){
                v2[k]=1;
            }
            else if(i%2 != 0 && v2.find(k)!= v2.end()){
                v1[k]=1;
            }
        }
        if(i%2 == 0) v1.clear();
        else v2.clear();
    }
    if(n%2 == 0){
        for(auto i : v2) cout << i.first << " ";
    }
    else{
        for(auto i : v1) cout << i.first << " ";
    }
    return 0;
}