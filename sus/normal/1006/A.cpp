#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void solve(){
    int n; cin >> n;
    int arr[n];
    int temp[n];
    for(int i=0; i<n; i++){
        int r; cin >> r;
        if(r%2==0){
            cout << r-1 << sp;
        }
        else{
            cout << r << sp;
        }
    }
    
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    fastIO();
    solve();
}