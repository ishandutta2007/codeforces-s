

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

/////////////////////////////////


int main(){
    ll n,k;cin>>n>>k;
    bool flag=true;
    
        for(int i=1;i<=k;i++){
            if(n%i!=i-1){
                flag=false;
                break;
            }
        }
    
    
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    return 0;
}