a,b,c,d = map(int,input().split())
res = 256*min(a,c,d)
a -= min(a,c,d)
c -= min(a,c,d)
d -= min(a,c,d)
res +=32*min(a,b)
print(res)