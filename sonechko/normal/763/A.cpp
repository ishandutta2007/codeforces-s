#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll unsigned long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
#define sqr(a) ((a)*(a))
vector<int> v[N];
int a[N],good;
void dfs(int l, int pr)
{
    for (int i=0; i<v[l].size(); i++)
    if (v[l][i]!=pr)
    {
        if (a[l]!=a[v[l][i]]&&pr!=0) {good=0;}
        dfs(v[l][i],l);
    }
}
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    sync;
    #endif
    int n;
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int l, r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int l=0,r=0;
    for (int i=1; i<=n; i++)
        for (int j=0; j<v[i].size(); j++)
    {
        if (a[i]!=a[v[i][j]])
        {
            l=i;
            r=v[i][j];
            break;
        }
    }
    if (l==0&&r==0) {cout<<"YES"<<endl; cout<<1<<endl; return 0;}
    good=1;
    dfs(l,0);
    if (good==1) {cout<<"YES"<<endl; cout<<l<<endl; return 0;}
    good=1;
    dfs(r,0);
    if (good==1) {cout<<"YES"<<endl; cout<<r<<endl; return 0;}
    cout<<"NO"<<endl;
}