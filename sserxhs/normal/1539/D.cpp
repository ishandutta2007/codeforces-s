#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define range(x) (x).begin(),(x).end()
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int sj(int n)
{
	unsigned int x=rnd();
	return x%n+1;
}
#define rand fst
template<typename typC> void read(register typC &x)
{
	register int c=getchar(),fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
template<typename typC> void read(register typC *a,int num)
{
	for (register int i=1;i<=num;i++) read(a[i]);
}
template<typename typC, typename... Args> void read(typC &first, Args& ... args) {
	read(first);
	read(args...);
}
template<typename typC> void write(register typC x)
{
	if (x<0) putchar('-'),x=-x;
	static int st[100];
	register int tp=1;
	register typC y;st[1]=x%10;x/=10;
	while (x) y=x/10,st[++tp]=x-y*10,x=y;++tp;
	while (--tp) putchar(st[tp]|48);
}
template<typename typC> void write(register typC *a,register int num)
{
	for (register int i=1;i<=num;i++) write(a[i]),putchar(i==num?10:32);
}
template<typename typC> typC ab(register typC x)
{
	if (x<0) return -x;
	return x;
}
#define space(x) write(x),putchar(32)
#define enter(x) write(x),putchar(10)
const int p=998244353;
const db eps=1e-9;
inline void inc(register int &x,const int y)
{
	if ((x+=y)>=p) x-=p;
}
inline void dec(register int &x,const int y)
{
	if ((x-=y)<0) x+=p;
}
inline int ksm(register int x,register int y)
{
	register int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
priority_queue<int> ONLYYFORRCOPYY;
priority_queue<int,vector<int>,greater<int> > ONLYYFORRCOPYY__;
struct Q
{
	ll u,v;
	Q(ll a=0,ll b=0):u(a),v(b){}
	bool operator<(const Q &o) const {return v<o.v;}
};
const int N=1e6+2,M=1e6+2,inf=1e9;
Q a[N];
ll ans,sum,cur;
int T,n,m,c,i,j,k,x,y,z,la,ksiz,ks;
multiset<ll> s;
multiset<ll>::iterator it;
int main()
{
	//ios::sync_with_stdio(false);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	read(n);
	for (i=1;i<=n;i++) read(a[i].u,a[i].v);
	sort(a+1,a+n+1);
	for (i=1;i<=n;i++) ans+=a[i].u;ans<<=1;
	for (i=n;i&&cur+a[i].u<=a[1].v;i--) cur+=a[i].u;
	a[i].u-=a[1].v-cur;
	int r=i;
	for (i=1;i<=r;i++) a[i].u+=a[i-1].u;
	for (i=1;i<=r;i++) s.insert(a[i].v-a[i-1].u);
	sum=a[1].v;
	//printf("%lld\n",sum);
	//for (i=1;i<=r;i++) printf("%lld %lld\n",a[i].u,a[i].v);
	for (i=r;i>=1;i--)
	{
		it=s.end();
		--it;
		cur=max((*it)-sum,0ll);
		ans=min(ans,cur+sum*2+a[i].u);
		//printf("%d %lld\n",i,cur+sum*2+a[i].u);
		s.erase(s.find(a[i].v-a[i-1].u));sum+=a[i].u-a[i-1].u;
	}
	enter(ans);
}