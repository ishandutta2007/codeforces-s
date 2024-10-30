
// *............    ..=^.,]]/O].*..[,OOO@@OO@@@@@@@@@@@@@@@@@@@@OO
// .........*=o`...,/@@@@@@@@@@@@@@]`...*..*=OO@@@@@@@@@@@O@@@@OOO
// ..,[`..,OO^..oO@@@@@@@@@@@@@@@@@@@Ooooo`]O@@@O@@@@@@@@@@@@@@@@
// O@@@@@OOOOOOO@@@@@@@@@@@@@@@@@@@@@@@O/`..[[[..[O/=O@O@@@O@@@@@@
// @@@@@@@@@@@O@@@@@@@@@@@@@@@@@@@O@@@@@O@@OOO]]/OO@@OO@@@@OOOOOOO
// ooOooo/[oooO@@@@@@@@@@@@OOOooOOoO@@@@O@@@OO@@@@@@@@@@@O@@@@@@@@
// OOOOOOOoOOOO@@@@OOOO/***......*,OOOOOOOOOOO@O\*/OOOOOOOOOO@@@@O
// ...........=@@@Ooo\***..........,\oooo*..*[[[ooooOoOOOOOOOOOO/[
// ...........=OOOoooo^****..........,\oo.........................
// ............@OO****...**............*..o.......................
// ............=/*,]/OOO]]]]oO/..................................
// ............\^*o`**/oOO^.*OO@[[[[`.........,]@@@@@@@@@@@@@@@@@@
// .............o*\/[]]]/*.........   ....../@@[[[[[[[[[[[[[[[[[[[
// .............**.............`...........=@^./@@`............./@
// ..............**....=^......=O]*........@@.=@@@@............=@@
// ...............\**,/OoO@@OO`.*oO\*.... .@@`.@@@@............=@@
// ...............,oooOO\]/O/OOO@OOo*..... ,@\.,@@@............=@@
// **,`**.*****.***=OooOOOO\]]O[..=o`....   ,@@`..[............,`.
// .*......,****..***OOOoOO]]OO^....*...      ,@@@\............=@@
// [***.....*......*...\O^,,[[.....****.         \@`..........,@@^
// ....................  .\Oo]]]]]oooo^           \@@]]....]]@@@`.
// **.....**.*****..   .  =OOOOOOOOOO.       ...     \@^...@@[....
// ........*.*.... .   .  ,,OOOOOOO/       ..     ,@@@@^...@@@@\**
// ..........*.*.  .  ,@@@@@@@@@@@@@@@@@`...  ./@@@@..........=@@@
// *.,`,*****`..  ..  ,@O\ \O@@@@@@O`/O@`...  @@OOOOOOOOOOOOOOOOOO
// .***,[`*.,*..  .. ...@O\ \O@@@@O`=@@.......@@@@@@@@@@@@@@@@@@@@
// ]***..*.... . ...     \@O =O\\O =@/.... ..`,`..................
// **..****.*. .....      @^..]]]..,@^... .... .       .          
// ******.**` ......     =^.=o].=o\.=@.. .....     .              
// *..*.***.  ......     =^.\o[.,oo.=@`...                        
// `..*/***.  ......     .@`.,[o/[.,@^.....                  ..   
// *]*..***.   ...........O@@\]]]/@@`./[`          ......         

#include<bits/stdc++.h>
#define int long long 
#define rd(x) x=read()
#define END {cout<<"IMPOSSIBLE"<<endl;return 0;}
using namespace std;
const int N=305;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
inline int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
inline int INV(int x){return ksm(x,mod-2);}

int A[N][N];
int n,m;
int a,b,c;
signed main()
{
    rd(n);rd(m);
    rd(a);rd(b);rd(c);
    if (n*m%2==1) END
    if (n%2==1)
    {
        //
        if (a<m/2) END
        for (register int i=1;i<=m;i+=2)
        {
            A[n][i]=A[n][i+1]=(i%4)/2+25;
            a--;
        }
    }
    if (m%2==1)
    {
        if (b<n/2) END
        for (register int i=1;i<=n;i+=2)
        {
            A[i][m]=A[i+1][m]=(i%4)/2+25;
            b--;
        }
    }
    int nn=n;int mm=m;
    n-=(n%2);m-=(m%2);
    if (a/2+b/2+c<n*m/4) END
    for (register int i=1;i<=n;i+=2)
        for (register int j=1;j<=m;j+=2)
        {
            int oe=((i%4/2)+(j%4/2))%2;
            oe*=2;
            if (a>1) 
            {
                A[i][j]=A[i][j+1]=oe+1;
                A[i+1][j]=A[i+1][j+1]=oe+2;
                a-=2;
            }else if (b>1)
            {
                A[i][j]=A[i+1][j]=oe+6;
                A[i][j+1]=A[i+1][j+1]=oe+7;
                b-=2;
            } else
            {
                A[i][j]=A[i+1][j]=A[i][j+1]=A[i+1][j+1]=oe+10;
                c--;
            }
            
            
        }
    if (a<0 || b<0 || c<0) END
    for (register int i=1;i<=nn;i++)
    {
        for (register int j=1;j<=mm;j++)
        {
            putchar(A[i][j]+'a'-1);
        }
        putchar('\n');
    }
}