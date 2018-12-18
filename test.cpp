#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define REPD(i,a,b) for(int i=a;i>=b;i--)
#define LL long long

#define ls (o<<1)
#define rs (o<<1|1)
const int N = 100005;
int n,m;
LL a[N],tag[N*4],sum[N*4];

void push_up(int o) {
	sum[o]=sum[rs]+sum[ls];
}

void build(int o,int l,int r) {
	if(l==r) {sum[o]=a[l];return;}
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	push_up(o);
}

void push_down(int o,int l,int r) {
	
	if(tag[o]) {
		int mid=(l+r) >> 1;
		tag[ls]+=tag[o]; tag[rs]+=tag[o];
		sum[ls]+=tag[o]*(mid-l+1); 
		sum[rs]+=tag[o]*(r-mid);
	}
	tag[o]=0;
}

void modify(int o,int l,int r,int ql,int qr,LL x) {
	if(ql<=l && qr>=r) {tag[o]+=x;sum[o]+=x*(r-l+1);return;}
	push_down(o,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid) modify(ls,l,mid,ql,qr,x);
	if(qr>mid) modify(rs,mid+1,r,ql,qr,x);
	push_up(o);
}

LL query(int o,int l,int r,int ql,int qr) {
	if(ql<=l && qr>=r) return sum[o];
	push_down(o,l,r);
	int mid=(l+r)>>1;
	LL tmp=0;
	if(ql<=mid) tmp+=query(ls,l,mid,ql,qr);
	if(qr>mid) tmp+=query(rs,mid+1,r,ql,qr);
	return tmp;
}

LL query_point(int o,int l,int r,int x) {
	if(l==r) return sum[o];
	push_down(o,l,r);
	int mid=(l+r)>>1;
	LL tmp=0;
	if(x<=mid) tmp+=query_point(ls,l,mid,x);
	else if(x>mid) tmp+=query_point(rs,mid+1,r,x);
	return tmp;
}

int main()
{
	scanf("%d%d",&n,&m);
	REP(i,1,n) scanf("%lld",&a[i]);
	build(1,1,n); 
	REP(i,1,m) {
		int x; scanf("%d",&x);
		if(x==1) {
			int y;
			LL k;
			scanf("%d%d%lld",&x,&y,&k);
			modify(1,1,n,x,y,k);
		}
		else {
			scanf("%d",&x);
			LL tmp=query_point(1,1,n,x);
			printf("%lld\n",tmp);
		}
	}
	return 0;
}