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
int a[N],dp[N][3];
int main()
{
#ifndef ONLINE_JUDGE
    filestxt;
    sync;
#endif

int n;
cin>>n;
for (int i=1; i<=n; i++)
    cin>>a[i];
if (a[1]==1||a[1]==3) {dp[1][2]=1;}
if (a[1]==2||a[1]==3) {dp[1][1]=1;}
for (int i=2; i<=n; i++)
{
    if (a[i]==2||a[i]==3) {dp[i][1]=max(dp[i-1][2],dp[i-1][0])+1;}
    if (a[i]==1||a[i]==3) {dp[i][2]=max(dp[i-1][1],dp[i-1][0])+1;}
    dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
}
cout<<n-max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
}