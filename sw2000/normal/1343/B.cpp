#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

void solve()
{
    int n;scanf("%d",&n);
    if(n%4)puts("NO");
    else
    {
        puts("YES");
        int sum=0;
        for(int i=2;i<=n;i+=2)
        {
            printf("%d ",i);
            sum+=i;
        }
        for(int i=1;i<n-1;i+=2)
        {
            printf("%d ",i);
            sum-=i;
        }
        printf("%d\n",sum);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        solve();
    }
    return 0;
}