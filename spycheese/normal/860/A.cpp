#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 100179;

string gg = "aeiou";
bool gb[256];

string solve(string s) {
    for (int i = 0; i + 3 <= sz(s); ++i) {
        if (!gb[s[i]] && !gb[s[i+1]] && !gb[s[i+2]] && (s[i] != s[i+1] || s[i+1] != s[i+2]))
            return s.substr(0, i + 2) + " " + solve(s.substr(i + 2, sz(s)-i-2));
    }
    return s;
}

int main() {
    for (char c : gg)
        gb[c] = true;
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    cout << solve(s) << "\n";

    return 0;
}