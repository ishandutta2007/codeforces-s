//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>

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
const int MOD = 1e9+7;
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
//string s;

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll n,h,a,b,k,ta,fa,tb,fb,ans;
    cin >> n >> h >> a >> b >> k;
    forn(i,k) {
        cin >> ta >> fa >> tb >> fb;
        if(ta == tb) ans = abs(fa-fb);
        else if((a <= fa && b >= fa) || (a <= fb && b >= fb) || (fa >= b && fb <=a) ||  (fb >= b && fa <=a)){
            ans = (abs(ta-tb) + abs(fa-fb));
        }
        else if(fa < a){
            ans = (abs(ta-tb) + abs(fa-a) + abs(fb-a));
        }
        else{
            ans = (abs(ta-tb) + abs(fa-b) + abs(fb-b));
        }
        cout << ans << ln;
        }
    return 0;
}