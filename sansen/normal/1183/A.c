#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

int ok (i32 n) {
  i32 sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum % 4 == 0;
}

void run (void) {
  i32 n = read_int();
  while (!ok(n)) ++n;
  print_int (n);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}