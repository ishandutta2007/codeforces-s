#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef long long int int64;

static void printInt(int64 n){
  if(n<0){putchar('-');n=-n;}
  if(n==0){putchar('0');return;}
  int s[20];int len=0;
  while(n>0){s[len++]=n%10+'0';n/=10;}
  while(len>0){putchar(s[--len]);}
}
static int64 readInt(void){
  int prev='\0';int c=getchar();
  while(!('0'<=c && c<='9')){prev=c;c=getchar();}
  int64 res=0;
  while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}
  return prev=='-'?-res:res;
}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void solve(const int ang){
  for(int i=3;;i++){
    for(int j=1;j<=i-2;j++){
      if(180*j%i==0 && 180*j/i==ang){
	printInt(i);
	putchar('\n');
	return;
      }
    }
  }
}

void run(void){
  int t=readInt();
  while(t--){
    int ang=readInt();
    solve(ang);
  }
}

int main(void){
  run();
  return 0;
}