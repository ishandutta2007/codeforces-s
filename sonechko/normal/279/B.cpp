#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100005;
const int M = 10;
const string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
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
#define next ljjdfienf
int n,a[N],b[N],ans;
int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    for (int i=1; i<=n; i++)
        if (a[i]<=m)
    {
        int l=i;
        int r=n;
        while (r-l>1)
        {
            int k=(l+r)/2;
            if (b[k]-b[i-1]<=m) l=k; else r=k;
        }
        if (b[r]-b[i-1]<=m) ans=max(ans,r-i+1); else ans=max(ans,l-i+1);
    }
    cout<<ans<<endl;
}