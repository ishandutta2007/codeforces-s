#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;
const int MOD = 1e9 + 7;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,x,y;
    cin>>n>>x>>y;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    if (x>y) {cout<<n<<endl; return 0;}
    sort(a+1,a+n+1);
    int p=0;
    for (int i=1; i<=n; i++)
        if (a[i]<=x) p++;
    cout<<(p+1)/2<<endl;
}