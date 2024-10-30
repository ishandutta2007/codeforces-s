#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))

void run (void) {
  i32 n = read_int();
  i32 x = read_int();
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
  }
  i64 ans = 0;
  i64 dp[3] = {0};
  for (i32 i = 0; i < n; ++i) {
    dp[2] = a[i] + MAX(dp[2], dp[1]);
    dp[1] = (i64) x * a[i] + MAX(dp[1], dp[0]);
    dp[0] = MAX(0, dp[0] + a[i]);
    ans = MAX(ans, MAX(dp[0], MAX(dp[1], dp[2])));
  }
  print_int (ans);
  puts("");
}

int main (void) {
  run ();
  return 0;
}