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
const int L=1e6+7;
map<ll,ll> leftis,rightis;
ll a[L],before[L],after[L],size_of_base;
std::vector<int>seg[4*L];
void build(int start = 1, int end = size_of_base, int index = 1)
{
	if( start == end )
	{
		seg[index].pb(after[start]);
		return;
	}
	int mid = (start + end)/2;
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);
	trace(seg[index<<1],x)seg[index].pb(x);
	trace(seg[2*index+1],x)seg[index].pb(x);
	sort(all(seg[index]));
	return;
}
ll query(int l, int r, ll x,int start = 1, int end = size_of_base, int index = 1)
{
	if( start > r || end < l )return 0;
	if(start >= l && end <= r)
	{
		return lower_bound(all(seg[index]),x)-seg[index].begin();
	}
	int mid = (start + end)/2;
	ll query_left, query_right;
	query_left = query(l, r, x,start, mid, 2*index );
	query_right = query(l, r,x, mid+1, end, 2*index + 1);
	return (query_left+ query_right);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin>>n;
	 	FOR(i,1,n+1)cin>>a[i];
		FOR(i,1,n+1)
		{
			leftis[a[i]]++;
			before[i]=leftis[a[i]];
		}
		RFOR(i,n,1)
		{
			rightis[a[i]]++;
			after[i]=rightis[a[i]];
		}
		size_of_base=n;
		build();
		ll ans=0;
		FOR(i,1,n+1)
		{
			ans+=query(i+1,n,before[i]);
		}
		cout<<ans;
		return 0;
}rn 0;
}