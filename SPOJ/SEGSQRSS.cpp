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
ll seg[400002],arr[1000002];
std::vector<ll> lazy[4000002];
void lazyupdate(ll s,ll e,ll index)
{
	// cout<<index<<endl;
	if(sz(lazy[index]))
	{
		for(auto &x:lazy[index])
		{
			seg[index]%=x;
			if(s!=e)
			{
				lazy[index<<1].pb(x);
				lazy[(index<<1)+1].pb(x);
			}
		}
		lazy[index].clear();
	}	
	return;
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
	seg[index]=seg[index<<1]+seg[(index<<1)+1];
	return;
}
ll query(ll s,ll e,ll l,ll r,ll index)
{
	if(index>400000)return 0;
	lazyupdate(s,e,index);
	if(e<l || s>r )return 0;
	ll q1,q2,mid=(s+e)/2;
	q1=query(s,mid,l,r,index<<1);
	q2=query(mid+1,e,l,r,(index<<1)+1);
	if(s>=l && e<=r && sz(lazy[index<<1])==0 && sz(lazy[(index<<1)+1])==0)
		return seg[index];
	
	return q1+q2;
}
void updateindex(int s,int e,int index,int updind,int val)
{
	lazyupdate(s,e,index);
	if(updind<s||updind>e)return;
	if(updind==s && updind==e)
	{
		seg[index]=val;
		return;
	}
	int mid=(s+e)/2;
	if(updind<=mid)
		updateindex(s,mid,index<<1,updind,val);
	else
		updateindex(mid+1,e,(index<<1)+1,updind,val);
	seg[index]=seg[index<<1]+seg[(index<<1)+1];
	return;
}
void updatemod(ll s,ll e,ll index,ll start,ll end,ll upd)
{
	lazyupdate(s,e,index);
	if(end<s||start>e || s>e)return;
	if(start<=s && end>=e)
	{
		seg[index]%=upd;
		if(s!=e)
		{
			lazy[index<<1].pb(upd);
			lazy[(index<<1)+1].pb(upd);
		}
		return;
	}
	ll mid=(s+e)/2;
	updatemod(s,mid,index<<1,start,end,upd);
	updatemod(mid+1,e,(index<<1)+1,start,end,upd);
	seg[index]=seg[index<<1]+seg[(index<<1)+1];
	return;
}
int main()
{
	 	ll m,n,l,r,v,type,k,x;
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