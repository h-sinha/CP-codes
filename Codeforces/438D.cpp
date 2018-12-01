#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
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
ll n,seg[400010],arr[1000002],segmax[400010];
void build(ll s,ll e,ll index)
{
	if(s>=e)
	{
		seg[index]=arr[s];
		segmax[index]=arr[s];
		return;
	}
	ll mid=(s+e)/2;
	build(s,mid,index<<1);
	build(mid+1,e,(index<<1)+1);
	seg[index]=seg[index<<1]+seg[(index<<1)+1];
	segmax[index]=max(segmax[index<<1],segmax[(index<<1)+1]);
	return;
}
ll query(ll s,ll e,ll l,ll r,ll index)
{
	if(e<l || s>r )return 0;
	if(s>=l && e<=r )
		return seg[index];
	ll q1,q2,mid=(s+e)/2;
	q1=query(s,mid,l,r,index<<1);
	q2=query(mid+1,e,l,r,(index<<1)+1);return q1+q2;
}
void updateindex(int s,int e,int index,int updind,int val)
{
	if(updind<s||updind>e)return;
	if(updind==s && updind==e)
	{
		seg[index]=val;
		segmax[index]=val;
		return;
	}
	int mid=(s+e)/2;
	if(updind<=mid)
		updateindex(s,mid,index<<1,updind,val);
	else
		updateindex(mid+1,e,(index<<1)+1,updind,val);
	seg[index]=seg[index<<1]+seg[(index<<1)+1];
	segmax[index]=max(segmax[index<<1],segmax[(index<<1)+1]);
	return;
}
ll querymax(ll s,ll e,ll l,ll r,ll index)
{
	if(e<l || s>r )return 0;
	if(s>=l && e<=r)
		return segmax[index];
	int q1,q2,mid=(s+e)/2;
	q1=querymax(s,mid,l,r,index<<1);
	q2=querymax(mid+1,e,l,r,(index<<1)+1);
	return max(q1,q2);
}
void updatemod(ll s,ll e,ll index,ll start,ll end,ll upd)
{
	if(end<s||start>e || s>e || segmax[index]<upd)return;
	if(s==e)
	{
		segmax[index]%=upd;
		seg[index]%=upd;
		return;
	}
	ll mid=(s+e)/2;
	updatemod(s,mid,index<<1,start,end,upd);
	updatemod(mid+1,e,(index<<1)+1,start,end,upd);
	seg[index]=seg[index<<1]+seg[(index<<1)+1];
	segmax[index]=max(segmax[index<<1],segmax[(index<<1)+1]);
	return;
}
int main()
{
	 	ios_base::sync_with_stdio(false);
		cin.tie(NULL);cout.tie(NULL);
		ll m,l,r,v,type,k,x;
	 	cin>>n>>m;
	 	FOR(i,1,n+1)cin>>arr[i];
	 	build(1,n,1);
	 	while(m--)
	 	{
	 		cin>>type;
	 		if(type==1)
	 		{
	 			cin>>l>>r;
	 			cout<<query(1,n,l,r,1)<<ln;
	 		}
	 		else if(type==2)
	 		{
	 			cin>>l>>r>>x;
	 			updatemod(1,n,1,l,r,x);
	 		}
	 		else
	 		{
	 			cin>>k>>x;
	 			arr[k]=x;
	 			updateindex(1,n,1,k,x);
	 		}
	 	}
		return 0;
}