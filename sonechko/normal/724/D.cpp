#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
const int N = 100+10;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define filestxt freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf1
#define last dkbffjrb
int a[N],gir[N],koli[N];
vector<int> pol[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int m;
    cin>>m;
    string s;
    cin>>s;
    int n=s.size();
    s='.'+s;
    s=s+"aaa";
    for (int i=1; i<=m; i++)
    {
        a[s[i]-'a']++;
    }
    for (int i=1; i<=n; i++)
    {
        pol[s[i]-'a'].push_back(i);
        koli[s[i]-'a']++;
    }
    int k=0;
    for (int i=1; i<=n-m+1; i++)
    {
    for (int j=0; j<26; j++)
            if (a[j]!=0) {k=max(k,j); break;}
    a[s[i]-'a']--;
    a[s[i+m]-'a']++;
    }
    for (int i=0; i<k; i++)
        for (int j=1; j<=koli[i]; j++)
    {
        char ch=i+'a';
        cout<<ch;
    }
    for (int i=0; i<=26; i++)
        a[i]=0;
    for (int i=1; i<=m; i++)
    {
        a[s[i]-'a']++;
    }
    int h=0;
    for (int j=0; j<k; j++)
        if (a[j]!=0) h=1;
    int pilot=0;
    int ans=0;
    if (h==1)
    {
        for (int i=1; i<=m; i++)
            if (s[i]-'a'<k) pilot=i;
    } else
    {
        ans=1;
        for (int i=1; i<=m; i++)
        if (s[i]-'a'==k) {pilot=i;}
    }
    int da=0;
    for (int i=1; i<=m; i++)
        if (s[i]-'a'==k) da=i;
    for (int i=2; i<=n-m+1; i++)
    {
        a[s[i-1]-'a']--;
        a[s[i+m-1]-'a']++;
        if (s[i+m-1]-'a'<k) pilot=i+m-1;
        if (s[i+m-1]-'a'==k) da=i+m-1;
        if (pilot<i) {ans++; pilot=da;}
    }
    for (int i=1; i<=ans; i++)
    {
        char ch=k+'a';
        cout<<ch;
    }
    cout<<endl;
}