#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))

void run (void) {
  i32 n = read_int();
  char *s = (char *) calloc (n + 1, sizeof (char));
  scanf ("%s", s);
  for (i32 i = 0; i + 1 < n; ++i) {
    if (s[i] > s[i + 1]) {
      puts("YES");
      print_int (i + 1);
      putchar (' ');
      print_int (i + 2);
      puts("");
      return;
    }
  }
  puts("NO");
}

int main (void) {
  run ();
  return 0;
}