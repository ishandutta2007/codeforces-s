/*
ID: Sfiction
OJ: CF
PROB: 294A
*/
#include <cstdio>
const int MAXN=100;
int a[MAXN];
int main()
{
    int N,M;
    int i,x,y;
    scanf("%d",&N);
    for (i=1;i<=N;++i) scanf("%d",&a[i]);
    scanf("%d",&M);
    for (i=0;i<M;++i)
    {
        scanf("%d%d",&x,&y);
        a[x-1]+=y-1;
        a[x+1]+=a[x]-y;
        a[x]=0;
    }
    for (i=1;i<=N;++i) printf("%d\n",a[i]);
    return 0;
}