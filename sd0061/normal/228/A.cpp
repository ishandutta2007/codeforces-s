#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
  int a[4],ans = 0; 
  for (int i = 0 ;i < 4 ;i ++)
    scanf("%d",&a[i]);
  sort(a,a + 4);
  for (int i = 0 ;i < 3 ;i ++)
    if (a[i] == a[i + 1])
      ans ++;
  printf("%d",ans);
  return 0;     
}