main(n,ans,x){scanf("%d",&n);ans=0;while(n--){scanf("%d",&x);ans|=x&1;}puts(ans?"First":"Second");};