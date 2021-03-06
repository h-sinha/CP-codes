#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=2e5+7;
int depth[L],tt=1,beg[L],ending[L],size_of_base,aa[L];
std::vector<int> v[L];
std::vector<ll> baseArray(L),seg(4*L),lazy(4*L);
void dfs(int vertex,int parent)
{
	depth[vertex]=depth[parent]+1;
	baseArray[tt++]=aa[vertex];
	beg[vertex]=tt-1;
	trace(v[vertex],x)
	{
		if(x!=parent)
			dfs(x,vertex);
	}
	ending[vertex]=tt-1;
	return;
}

void build(int start = 1, int end = size_of_base, int index = 1)
{
	if( start == end )
	{
		seg[index] = baseArray[start];
		return;
	}
	int mid = (start + end)/2;
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);
	seg[index] = (seg[2*index] + seg[2*index + 1]);
	return;
}
void lazyUpdate(int start, int end, int index)
{
	if(lazy[index] != 0)
	{
		if((end-start+1)%2!=0)
		seg[index] += lazy[index];
		if(start != end)
		{
			// int mid=(start+end)/2;
			// if((mid-start+1) %2!=0)
			lazy[2*index] +=  lazy[index];
			// if((end-mid+1) %2!=0)
			lazy[2*index + 1] +=  lazy[index];
		// lazy[2*index] += lazy[index];
			// lazy[(2*index) + 1] += lazy[index];
		}
		lazy[index] = 0;
	}
	return;
}
void updateRange(int l, int r, ll value, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate(start, end, index);
	if(r < start || l > end || start > end )return;
	if( l <= start && r >= end )
	{
		if((end-start+1) %2!=0)seg[index]+=value;
		if(start != end)
		{
			// int mid=(start+end)/2;
			// if((mid-start+1) %2!=0)
			lazy[2*index] +=  value;
			// if((end-mid+1) %2!=0)
			lazy[2*index + 1] +=  value;
		}
		return;
	}
	int mid = (start + end)/2;
	updateRange(l, r, value, start, mid, 2*index );
	updateRange(l, r, value, mid+1, end, 2*index + 1);
	seg[index] = (seg[2*index] + seg[2*index + 1]) ;
	return;
}
ll query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate(start, end, index);
	if( start > r || end < l || start > end)
		return 0;
	if(start >= l && end <= r)
		return seg[index];
	int mid = (start + end)/2, query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	return (query_left + query_right);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,m,a,b;
	 	cin>>n>>m;
	 	FOR(i,1,n+1)cin>>aa[i];
	 	FOR(i,0,n-1)
	 	{
	 		cin>>a>>b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	dfs(1,0);
	 	FOR(i,1,n+1)
	 	{
	 		if(depth[i]%2)depth[i]=-1;
	 		else depth[i]=1;
	 	}
	 	size_of_base=tt-1;
	 	build();
	 	// FOR(i,1,n+1)cout<<i<<" - "<<depth[i]<<ln;
	 	// FOR(i,1,n+1)cout<<i<<" - "<<query(beg[i],beg[i])<<ln;
	 	int type;
	 	while(m--)
	 	{
	 		cin>>type;
	 		if(type==1)
	 		{
	 			cin>>a>>b;
	 			if(depth[a]==-1)updateRange(beg[a],ending[a],-b);
	 			else updateRange(beg[a],ending[a],b);
	 		}
	 		else
	 		{
	 			cin>>a;
	 			cout<<query(beg[a],beg[a])<<ln;
	 		}
	 	}
		return 0;
}