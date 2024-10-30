#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 100005
int n;
int a[MN];
int app[35];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    F0R(i, n){
        cin >> a[i];
        F0R(j, 31){
            if((1<<j) & a[i]){
                ++app[j];
            }
        }
    }
    int loc = -1;
    RFOR(i, 30, 0){
        if(app[i] == 1){
            loc = i;
            break;
        }
    }
    if(loc == -1){
        F0R(i, n){
            cout << a[i] << " ";
        }
        return 0;
    } else{
        int ans = 0;
        F0R(i, n){
            if((1<<loc) & a[i]){
                ans = i;
                break;
            }
        }
        cout << a[ans] << " ";
        F0R(i, n){
            if(i == ans) continue;
            cout << a[i] << " ";
        }
    }

    return 0;
}