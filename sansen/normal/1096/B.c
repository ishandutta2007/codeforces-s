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

void run(void){
  int n=readInt();
  char *s=(char *)calloc(n+1,sizeof(char));
  scanf("%s",s);
  int64 ans=1;
  int i;
  for(i=0;s[i]==s[0];i++) ans++;
  int j;
  for(j=0;s[n-1-j]==s[n-1];j++) ans++;
  if(s[0]==s[n-1]){
    ans+=(int64)i*j;
  }
  printInt(ans%998244353);
  putchar('\n');
}

int main(void){
  run();
  return 0;
}