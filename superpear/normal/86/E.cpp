#include <iostream>
#include <cstring>

using namespace std;

int main()
{
string s[100];
s[2]="1 1";
s[3]="1 0 1";
s[4]="1 0 0 1";
s[5]="0 1 1 1 1";
s[6]="1 0 0 0 0 1";
s[7]="1 1 1 1 1 0 1";
s[8]="0 1 1 0 0 0 1 1";
s[9]="1 1 1 0 0 1 0 1 1";
s[10]="1 1 0 1 1 0 0 0 1 1";
s[11]="1 1 0 0 0 0 1 1 1 0 1";
s[12]="1 0 1 0 0 0 0 1 1 0 1 1";
s[13]="1 1 0 1 1 0 0 1 1 1 1 1 1";
s[14]="0 1 1 1 0 0 0 1 1 1 1 0 0 1";
s[15]="1 0 1 1 0 0 1 1 0 0 0 1 0 1 1";
s[16]="1 0 0 1 0 1 0 1 1 0 0 0 1 1 0 1";
s[17]="1 1 0 0 0 0 1 0 1 1 1 0 0 1 1 1 1";
s[18]="0 0 1 0 1 0 0 0 1 1 1 1 1 0 1 0 1 1";
s[19]="0 1 1 0 0 0 0 1 1 0 0 0 0 1 0 1 1 0 1";
s[20]="1 1 1 1 1 1 0 0 0 0 0 1 1 1 0 1 1 0 0 1";
s[21]="0 0 1 0 1 1 1 1 1 0 0 0 0 0 0 0 1 1 1 0 1";
s[22]="0 0 1 0 0 1 1 1 1 1 0 0 0 1 1 1 1 0 0 0 1 1";
s[23]="1 1 1 0 1 0 1 1 0 0 1 1 1 1 0 1 1 1 1 1 0 0 1";
s[24]="0 0 0 0 0 0 0 0 1 1 1 0 0 1 1 1 1 1 1 0 1 1 0 1";
s[25]="0 1 0 0 0 0 1 0 1 0 0 1 1 0 1 1 0 1 1 0 0 1 0 1 1";
s[26]="0 0 0 1 1 1 1 0 1 0 0 1 1 0 1 0 1 0 0 1 1 1 1 0 0 1";
s[27]="1 0 1 0 1 1 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 0 0 0 1 1";
s[28]="1 0 1 1 1 0 1 1 1 1 1 1 1 0 1 1 1 0 1 0 1 1 1 0 1 0 0 1";
s[29]="0 0 0 1 1 1 1 0 1 0 1 1 1 0 0 1 1 0 1 0 1 0 1 1 0 0 0 1 1";
s[30]="0 1 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1 0 0 1 0 0 0 0 0 1 1";
s[31]="0 1 0 1 0 0 1 0 0 0 1 0 1 1 0 0 1 1 0 0 0 0 0 0 1 0 1 1 0 0 1";
s[32]="0 1 0 1 0 1 1 0 1 0 0 0 1 1 1 1 0 0 1 1 1 1 0 0 0 0 1 0 0 1 0 1";
s[33]="0 1 0 0 0 0 0 1 0 0 0 0 1 0 1 1 0 1 0 1 0 1 0 0 1 0 0 1 1 0 1 1 1";
s[34]="1 0 1 0 1 1 1 1 1 0 1 1 0 1 0 0 1 1 1 1 0 1 0 0 1 0 0 1 0 0 0 0 0 1";
s[35]="0 1 1 1 0 0 0 0 1 0 1 1 1 1 0 0 0 1 1 0 1 0 0 1 0 0 1 1 1 1 0 1 0 0 1";
s[36]="1 1 1 1 1 1 0 0 1 0 1 1 1 0 1 0 0 1 1 1 1 1 1 1 1 1 0 0 1 0 1 1 1 1 0 1";
s[37]="1 0 1 0 0 1 0 0 0 1 0 1 1 1 0 1 1 1 0 1 1 1 0 0 1 1 1 1 1 1 1 1 1 1 0 0 1";
s[38]="1 1 0 0 1 1 1 1 0 1 0 1 0 0 1 0 0 1 0 0 1 1 1 0 1 0 0 0 1 0 1 1 1 1 0 1 1 1";
s[39]="1 1 0 1 0 1 0 0 1 1 1 1 1 1 0 0 1 0 0 0 1 1 1 1 1 0 0 1 1 0 1 0 1 0 0 1 0 0 1";
s[40]="1 0 0 1 0 0 0 0 1 1 0 1 0 0 0 0 1 1 0 1 1 1 1 1 1 0 0 0 1 0 1 1 1 0 0 0 1 1 0 1";
s[41]="1 1 1 0 0 0 1 1 1 1 0 0 0 1 1 1 0 1 1 0 1 1 1 0 1 0 1 0 0 0 0 0 0 1 0 1 0 1 0 1 1";
s[42]="0 1 0 1 1 1 0 0 1 0 0 0 0 0 0 1 0 1 1 1 1 1 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1";
s[43]="0 0 1 0 0 0 0 1 1 0 1 1 1 0 1 0 1 0 1 0 1 0 0 1 0 1 1 1 0 1 1 1 1 1 0 0 0 0 1 1 1 1 1";
s[44]="1 1 1 1 1 0 0 1 0 0 1 1 1 0 1 0 0 0 0 0 1 0 1 1 0 1 1 1 1 0 1 0 1 0 0 0 1 1 1 0 1 1 1 1";
s[45]="1 1 1 0 1 0 1 0 0 0 1 0 1 0 0 1 1 1 1 0 1 1 0 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 0 1 0 0 1 1";
s[46]="1 0 0 1 0 0 0 1 1 0 1 0 0 0 0 0 1 0 1 0 0 1 1 0 0 0 0 0 1 0 0 1 0 0 1 0 1 0 1 0 1 0 1 0 1 1";
s[47]="1 0 0 1 0 1 0 0 1 1 1 1 1 1 0 0 0 0 1 0 0 0 0 1 1 0 0 0 1 0 1 1 1 1 0 0 0 0 1 1 0 1 0 1 1 1 1";
s[48]="1 1 1 1 1 0 0 1 0 1 0 0 0 1 1 1 0 1 0 0 1 0 1 0 1 1 0 1 0 0 1 1 0 0 1 1 1 0 1 1 1 1 1 0 1 1 1 1";
s[49]="0 1 1 1 0 0 1 0 1 0 0 1 1 1 1 1 0 0 1 1 1 0 1 0 1 0 0 1 0 1 0 0 1 0 0 1 1 1 1 0 0 0 1 1 1 1 0 1 1";
s[50]="0 0 0 0 0 1 1 1 0 1 1 0 1 1 1 0 0 1 1 1 1 0 0 0 0 0 0 1 1 1 0 1 1 0 1 0 1 1 1 1 1 0 1 0 0 1 0 0 0 1";

int k;
cin>>k;
cout<<s[k]<<endl;
for (int i=1;i<k;i++) cout<<"1 ";cout<<"1"<<endl;
return 0;
}