#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<double, double> PDD;

const int maxlongint = 2147483647;
const int biglongint = 2139062143;

#define w1 first
#define w2 second
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound

int main()
{
	string st;
	cin >> st;
	if ((st[0] >= 'a') && (st[0] <= 'z'))
		st[0] -= 32;
	cout << st << endl;
	return 0;
}