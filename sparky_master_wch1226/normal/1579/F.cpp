#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
void solve(int TC) {
    int n, d;
    cin >> n >> d;
    int arr[n + 5];
    bool vi[n + 5];
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        vi[i]= false;
    }
    for(int i = 0; i < n; i++) {
        if(!vi[i] && arr[i] == 0) {
            int now = i;
            int tc = 0;
            while(!vi[now]) {
                if(arr[now] == 1) tc++;
                else tc = 0;
                cnt = max(cnt, tc);
                vi[now] = true;
                now = (now + d) % n; 
            }
        }
    }
    for(int i = 0; i < n; i++) if(!vi[i]) {
        cout << "-1\n";
        return;
    }
    cout << cnt << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}