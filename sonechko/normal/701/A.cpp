#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 3000000+5;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define filestxt freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
//#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
int b[N],use[N];
int main()
{
#ifndef ONLINE_JUDGE
    filestxt;
#endif
sync;
int n;
cin>>n;
int mini=101,maxi=0;
for (int i=1; i<=n; i++)
{
    int l;
    cin>>l;
    b[i]=l;
    mini=min(mini,l);
    maxi=max(maxi,l);
}
int sum=mini+maxi;
for (int i=1; i<=n; i++)
    if (use[i]==0)
{
    use[i]=1;
for (int j=1; j<=n; j++)
if (use[j]==0&&b[j]+b[i]==sum) {use[j]=1; cout<<i<<" "<<j<<endl; break;}
}
}