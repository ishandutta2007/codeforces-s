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

#define int long long

void read()
{
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    a -= x;
    if (a < 0)
    {
        cout << "NO";
        exit(0);
    }
    a += b;
    a -= y;
    if (a < 0)
    {
        cout << "NO";
        exit(0);

    }
    a += c;
    a -= z;
    if (a < 0)
    {
        cout << "NO";
        exit(0);
    }
    cout << "YES";
}

void run()
{

}

void write()
{

}

signed main()
{
    FAST;
    read();
    run();
    write();
    return 0;
}