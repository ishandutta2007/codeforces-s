#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	reverse(s1.begin(), s1.end());
	if (s1 == s2)
		cout << "YES" << endl; else
		cout << "NO" << endl;
	return 0;
}