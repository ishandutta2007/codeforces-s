#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 500001;
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
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
int a[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int ans=0;
    if (a[m]==1) ans++;
    for (int i=1; i<=n; i++)
    {
        if (m-i<1) ans+=a[m+i];
        if (m+i>n&&m-i>=1) ans+=a[m-i];
        if (m-i>0&&m+i<=n)
        {
            if (a[m-i]==a[m+i]) ans+=a[m-i]*2;
        }
    }
    cout<<ans<<endl;
}