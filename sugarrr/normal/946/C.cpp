

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
#define inf 100000000/*10^8*/
#define rep(i,l,r) for(int i=l;i<=r;i++)
const double EPS=1E-8;

////////////////////////////////////////


int main() {
    char s[100005];cin>>s;
    int len=strlen(s);
    int pos=25;
    char q[27]="abcdefghijklmnopqrstuvwxyz";
    bool flag=false;
    for(int i=len-1;i>=0;i--){
        if(s[i]<=q[pos]){
            s[i]=q[pos];
            pos--;
        }
        if(pos==-1){
            flag=true;
            break;
        }
    }
    if(flag){
        cout<<s<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}