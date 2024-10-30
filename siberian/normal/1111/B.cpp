#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops") 
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <stdio.h>

using namespace std;
#define FAST ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr)

#define int long double
int n, k, m;
int sum;
vector <int> a;
void read()
{
    sum = 0;
    cin >> n >> k >> m;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
}
int ans;
void run()
{
    ans = sum / n;
    for (int i = 0; i < min(n, m + 1); i++)
    {
        int cnt = sum;
        int plus = min(m - i, k*(n - i));
        ans = max(ans, (cnt + plus) / (n - i));
        sum -= a[i];
    }
}

void write()
{
    cout.precision(20);
    cout << ans;
}

signed main()
{
    FAST;
    read();
    run();
    write();
    return 0;
}