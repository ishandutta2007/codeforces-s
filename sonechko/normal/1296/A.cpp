#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void up()
{
    int n;
    cin>>n;
    int k0=0,k1=0;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        if (x%2==0) k0++; else k1++;
    }
    if (k1==0) cout<<"NO\n"; else
    if (k0==0&&n%2==0) cout<<"NO\n"; else cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}