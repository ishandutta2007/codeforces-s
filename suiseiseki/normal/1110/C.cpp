#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	int a;
	for(int i=1,j;i<=n;i++){
		scanf("%d",&a);
		if(a==3){
			puts("1");
			continue;
		}
		if(a==7){
			puts("1");
			continue;
		}
		if(a==15){
			puts("5");
			continue;
		}
		if(a==31){
			puts("1");
			continue;
		}
		if(a==63){
			puts("21");
			continue;
		}
		if(a==127){
			puts("1");
			continue;
		}
		if(a==255){
			puts("85");
			continue;
		}
		if(a==511){
			puts("73");
			continue;
		}
		if(a==1023){
			puts("341");
			continue;
		}
		if(a==2047){
			puts("89");
			continue;
		}
		if(a==4095){
			puts("1365");
			continue;
		}
		if(a==8191){
			puts("1");
			continue;
		}
		if(a==16383){
			puts("5461");
			continue;
		}
		if(a==32767){
			puts("4681");
			continue;
		}
		if(a==65535){
			puts("21845");
			continue;
		}
		if(a==131071){
			puts("1");
			continue;
		}
		if(a==262143){
			puts("87381");
			continue;
		}
		if(a==524287){
			puts("1");
			continue;
		}
		if(a==1048575){
			puts("349525");
			continue;
		}
		if(a==2097151){
			puts("299593");
			continue;
		}
		if(a==4194303){
			puts("1398101");
			continue;
		}
		if(a==8388607){
			puts("178481");
			continue;
		}
		if(a==16777215){
			puts("5592405");
			continue;
		}
		if(a==33554431){
			puts("1082401");
			continue;
		}
		for(j=30;j>=0;j--){
			if(a&(1<<j)){
				break;
			}
		}
		printf("%d\n",(1<<(j+1))-1);
	}
	return 0;
}