#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <deque>

#define fab(i, a, b) for(int i = a; i <= b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define pint pair <int, int>
#define vint vector <int>
#define vpint vector < pair <int, int> >
#define ff first
#define ss second
#define cpr(n) cout.precision(n);

typedef long long ll;
typedef long double ld;
typedef double db;

const ll inf = 1e9;
const ld eps = 1e-6;
const ll N = 1e6;
const ll M = 1e6;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

int n, ans = 1, k = 0, h, len, pr = 0;
int l, r;
int a[N];
string s;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (n < 3) ret("-1");
    if (n == 3) ret("210");
    n--;
    int ost = 1;
    fr(i, n - 1) ost = (ost * 10) % 21;
    ost = 21 - ost;
    s = "1";
    fr(i, n) s += "0";
    while(ost != 0){
        s[--n] = '0' + ost % 10;
        ost /= 10;
    }
    cout << s;
    return 0;
}