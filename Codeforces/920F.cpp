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
std::vector<int> divsize(1000002,2);
ll n,arr[300002],seg[1200010],seg1[1200010],lazy[1200010];
void build(ll s,ll e,ll index)
{
	if(s>=e)
	{
		seg[index]=arr[s];
		seg1[index]=arr[s];
		return;
	}
	ll mid=(s+e)/2;
	build(s,mid,index<<1);
	build(mid+1,e,(index<<1)+1);
	seg[index]=seg[index<<1]+seg[(index<<1)+1];
	seg1[index]=max(seg1[index<<1],seg1[(index<<1)+1]);
	return;
}
ll querymax(ll s,ll e,ll l,ll r,ll index)
{
	if(e<l || s>r )return 0;
	if(s>=l && e<=r)
		return seg1[index];
	int q1,q2,mid=(s+e)/2;
	q1=querymax(s,mid,l,r,index<<1);
	q2=querymax(mid+1,e,l,r,(index<<1)+1);
	return max(q1,q2);
}
ll query(ll s,ll e,ll l,ll r,ll index)
{
	if(e<l || s>r )return 0;
	if(s>=l && e<=r)
		return seg[index];
	ll q1,q2,mid=(s+e)/2;
	q1=query(s,mid,l,r,index<<1);
	q2=query(mid+1,e,l,r,(index<<1)+1);
	return (q1+q2);
}
void update(ll s,ll e,ll index,ll start,ll end)
{
	if(end<s||start>e || s>e)return;
	if(start<=s && end>=e)
	{
		ll temp=querymax(1,n,s,e,1);
		if(temp<=2)return;
		FOR(i,s,e+1)
			arr[i]=divsize[arr[i]];
		build(s,e,index);
		return;
	}
	ll mid=(s+e)/2;
	update(s,mid,index<<1,start,end);
	update(mid+1,e,(index<<1)+1,start,end);
	seg[index]=(seg[index<<1]+seg[(index<<1)+1]);
	seg1[index]=max(seg1[index<<1],seg1[(index<<1)+1]);
	return;
}
int  main()
{
	 	ios_base::sync_with_stdio(false);
		cin.tie(NULL);ll cur=0,m,type,t,c,v,p,q;
	 	cin>>n>>m;
	 	divsize[1]=1;
		FOR(i,2,1000001)
		for(int j=2*i;j<=1000000;j+=i)
			divsize[j]++;
	 	FOR(i,1,n+1)cin>>arr[i];
	 	build(1,n,1);
	 	while(m--)
	 	{
	 		cin>>type>>p>>q;
	 		if(type==1)
	 			update(1,n,1,p,q);
	 		else 
	 			cout<<query(1,n,p,q,1)<<"\n";
	 	}
		return 0;
}