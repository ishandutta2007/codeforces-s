#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void solve(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        int zcounter = 0;
        bool mat = false;
        bool hasz = false;
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i]==arr[j]){
                    mat = true;
                    break;
                }
            }
            if(arr[i]==0) {
                hasz = true;
                zcounter++;
                //cout << "am here" << ln;
            }
            
        }
        if(hasz){

            cout << n-zcounter << ln;
        }
        else if(mat){
            cout << n << ln;
        }
        else{
            cout << n+1 << ln;
        }
    }
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}