#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

int n, vol;
std::string str;

int main() {
    std::cin >> n >> str;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') { printf("%d", vol & 1); vol++; }
        else { vol--; printf("%d", vol & 1); }
    }
    return 0;
}