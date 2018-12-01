#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
ll arr[200002],seg[800010],lazy[800010];
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
void build(ll s,ll e,ll index)
{
	if(s>=e)
	{
		seg[index]=arr[s];
		return;
	}
	ll mid=(s+e)/2;
	build(s,mid,index<<1);
	build(mid+1,e,(index<<1)+1);
	seg[index]=min(seg[index<<1],seg[(index<<1)+1]);
	return;
}
ll query(ll s,ll e,ll l,ll r,ll index)
{
	if(lazy[index]!=0)
	{
		seg[index]+=lazy[index];
		if(s!=e)
		{
			lazy[index<<1]+=lazy[index];
			lazy[(index<<1)+1]+=lazy[index];
		}
		lazy[index]=0;
	}
	if(e<l || s>r )return LLONG_MAX;
	if(s>=l && e<=r)
		return seg[index];
	ll q1,q2,mid=(s+e)/2;
	q1=query(s,mid,l,r,index<<1);
	q2=query(mid+1,e,l,r,(index<<1)+1);
	return min(q1,q2);
}
void update(ll s,ll e,ll index,ll start,ll end,ll upd)
{
	if(lazy[index]!=0)
	{
		seg[index]+=lazy[index];
		if(s!=e)
		{
			lazy[index<<1]+=lazy[index];
			lazy[(index<<1)+1]+=lazy[index];
		}
		lazy[index]=0;
	}
	if(end<s||start>e || s>e)return;
	if(start<=s && end>=e)
	{
		seg[index]+=upd;
		if(s!=e)
		{
			lazy[index<<1]+=upd;
			lazy[(index<<1)+1]+=upd;
		}
		return;
	}
	ll mid=(s+e)/2;
	update(s,mid,index<<1,start,end,upd);
	update(mid+1,e,(index<<1)+1,start,end,upd);
	seg[index]=min(seg[index<<1],seg[(index<<1)+1]);
	return;
}
int main()
{
	 	ll m,n,l,r,v;
	 	cin>>n;
	 	FOR(i,1,n+1)cin>>arr[i];
	 	build(1,n,1);
	 	cin>>m;
	 	char c;
	 	while(m--)
	 	{
	 		l=LONG_MAX,r=LLONG_MAX,v=LLONG_MAX;
	 		scanf("%lld%lld%c",&l,&r,&c);
	 		if(c!='\n')cin>>v;
	 		l++,r++;
	 		if(v!=LLONG_MAX)
	 		{
	 			if(r<l)
	 			{
	 				update(1,n,1,l,n,v);
	 				update(1,n,1,1,r,v);
	 			}
				else update(1,n,1,l,r,v);
			}		
			else 
			{
	 			if(r<l)
	 			{
	 				ll q1=query(1,n,l,n,1);
	 				ll q2=query(1,n,1,r,1);
	 				cout<<min(q1,q2)<<ln;
	 			}
				else cout<<query(1,n,l,r,1)<<ln;
			}
	 	}
		return 0;
}