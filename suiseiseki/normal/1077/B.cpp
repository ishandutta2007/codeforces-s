#include <cstdio>
int a[105];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int i=2;i<n;i++){
		if(a[i]==0&&a[i-1]==1&&a[i+1]==1){
			ans++;
			a[i+1]=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}