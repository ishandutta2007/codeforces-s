#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 100000+10;
const int M = 100;
const int N2 = 100+5;
const int N3 = 1000+5;
const int N4 = 10000+5;
const int N5 = 100000+5;
const int N6 = 1000000+5;
const int N7 = 10000000+5;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define filestxt freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sqr(a) ((a) * (a))
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfjh
#define ull unsigned long long
#define next ifhiuebf
#define last dkbffjrb
#define pb push_back
#define pii pair<int,int>
vector<int> p;
bool prost(int n)
{
    int sq=(int)sqrt(n);
    for (int i=2; i<=sq; i++)
        if (n%i==0) return false;
    return true;
}
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    ll n;
    cin>>n;
    if (prost(n)) cout<<1<<endl; else
    if (prost(n-2)) cout<<2<<endl; else
    if (prost(n-3)) cout<<2<<endl; else
    if (prost(n-5)) cout<<2<<endl; else
    if (n%2==0) cout<<2<<endl; else
    cout<<3<<endl;
}