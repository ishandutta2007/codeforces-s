#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
struct tri{int x,y,z;};
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;
int solve()
{
    int n,x;
    cin>>n>>x;
    if(n<=2)return 1;
    else n-=3;
    return n/x+2;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    int two[32];
    two[0]=1;
    for(int i=1;i<31;i++)
        two[i]=1<<i;
    while(_--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}