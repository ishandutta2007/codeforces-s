/*
* C++11 code template for contests.
* @author: Andrey Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

/*______ DEFINES _______*/

#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
//#define ANDREIKKAA_TOPCODER
//#define ANDREIKKAA_ALLOCATOR
#define ANDREIKKAA_CLASS Solution
#define ANDREIKKAA_METHOD solve
#define ANDREIKKAA_PARAMETERS void
#define ANDREIKKAA_CALL
#define ANDREIKKAA_RETURN_TYPE void
typedef long long ll;
typedef long double ld;
const int MEMORY_LIMIT_MB = 200;
const int TIME_LIMIT_S = 1;
const char input_filename[] =
#if defined(ANDREIKKAA)
"input.txt"
#else
""
#endif
;
const char output_filename[] =
#if defined(ANDREIKKAA)
""
#else
""
#endif
;

/* ______ INCLUDES ______ */
#include <cassert>
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <locale>
#include <numeric>
#include <regex>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

/* _____ ALLOCATION _____ */

#if defined(ANDREIKKAA_ALLOCATOR)
char alloc_memory[MEMORY_LIMIT_MB * 1000 * 1000];
size_t alloc_pointer = 0;
inline void* operator new(size_t x) { alloc_pointer += x; return alloc_memory + alloc_pointer - x; }
inline void operator delete(void*) { }
#endif

/*____ I-O OPERATORS ____*/
template<typename T, typename U> inline ostream &operator<<(ostream &out, const pair<T, U> &p) { out << p.first << ' ' << p.second; return out; }
template<typename T, typename U> inline istream &operator >> (istream &in, pair<T, U> &p) { in >> p.first >> p.second; return in; }
template<typename T> inline ostream &operator<<(ostream &out, const vector<T> &v) { if (v.empty()) return out; out << v.front(); for (auto it = ++v.begin(); it != v.end(); ++it) out << ' ' << *it; return out; }
template<typename T> inline istream &operator >> (istream &in, vector<T> &v) { for (auto &i : v) in >> i; return in; }

/* ________ CODE ________ */

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int t;
	cin >> t;
	for(int hui = 0; hui < t; ++hui)
	{
		int n;
		cin >> n;

		if (n == 1)
		{
			cout << "! 1 1" << endl;
			continue;
		}

		vector<int> mx, mn;
		for (int i = 1; i + 1 <= n; i += 2)
		{
			cout << "? " << i << " " << i + 1 << endl;
			char c;
			cin >> c;
			if (c == '<' or c == '=')
			{
				mn.push_back(i);
				mx.push_back(i + 1);
			}
			else
			{
				mx.push_back(i);
				mn.push_back(i + 1);
			}
		}
		for (int i = 1; i < mx.size(); ++i)
		{
			cout << "? " << mx[0] << " " << mx[i] << endl;
			char c;
			cin >> c;
			if (c == '<')
			{
				swap(mx[0], mx[i]);
			}
		}
		for (int i = 1; i < mn.size(); ++i)
		{
			cout << "? " << mn[0] << " " << mn[i] << endl;
			char c;
			cin >> c;
			if (c == '>')
			{
				swap(mn[0], mn[i]);
			}
		}
		int mnn = mn[0], mxx = mx[0];
		if (n & 1)
		{
			cout << "? " << mn[0] << " " << n << endl;
			char c;
			cin >> c;
			if (c == '>')
			{
				mnn = n;
			}

			cout << "? " << mx[0] << " " << n << endl;
			cin >> c;
			if (c == '<')
			{
				mxx = n;
			}
		}

		cout << "! " << mnn << " " << mxx << endl;
		cout.flush();
	}
}

class ANDREIKKAA_CLASS
{
public:
	ANDREIKKAA_RETURN_TYPE ANDREIKKAA_METHOD(ANDREIKKAA_PARAMETERS)
	{
#ifdef ANDREIKKAA
		//freopen("input.txt", "r", stdin);
#endif
		//cin.tie(nullptr);
		//ios_base::sync_with_stdio(false);
		//cout << setprecision(20);
		//cout << fixed;
		return mainFunction(ANDREIKKAA_CALL);
	}
#if defined(ANDREIKKAA)
	inline ANDREIKKAA_CLASS() { _start = clock(); }
	inline ~ANDREIKKAA_CLASS() { cerr << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl; }
private:
	time_t _start;
#endif
};

#if defined(ANDREIKKAA) || !defined(ANDREIKKAA_TOPCODER)
int main()
{
	auto _s = new ANDREIKKAA_CLASS; _s->ANDREIKKAA_METHOD(ANDREIKKAA_CALL); delete _s;
#if defined(ANDREIKKAA)
	while (true);
#endif
}
#endif