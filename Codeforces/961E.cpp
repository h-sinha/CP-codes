#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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
const ll L=2e5+7;
ll baseArray[L],size_of_base;
vector<ll>seg[4*L];
void build(ll start = 1, ll end = size_of_base, ll index = 1)
{
	if( start == end )
	{
		seg[index].pb(baseArray[start]);
		return;
	}
	ll mid = (start + end)/2;
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);
	trace(seg[index<<1],x)seg[index].pb(x);
	trace(seg[(index<<1)+1],x)seg[index].pb(x);
	sort(all(seg[index]));
	return;

}
ll query(ll l, ll r,ll val ,ll start = 1, ll end = size_of_base, ll index = 1)
{
	if( start > r || end < l )return 0;
	// cout<<start<<" & "<<end<< " &"<<l<<" "<<r<<ln;
	if(start >= l && end <= r)
	{
		// cout<<"val"<<val<<ln;
		// trace(seg[index],x)cout<<x<<" - ";
		// cout<<ln;
		return sz(seg[index])-(lower_bound(all(seg[index]),val)-seg[index].begin());
	}
	ll mid = (start + end)/2;
	ll query_left, query_right;
	query_left = query(l, r, val,start, mid, 2*index );
	query_right = query(l, r,val, mid+1, end, 2*index + 1);
	return (query_left+ query_right);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	size_of_base=n;
	FOR(i,1,n+1)cin >> baseArray[i];
	build();
	ll ans=0;
	FOR(i,1,n+1)
		ans+=query(i+1,baseArray[i],i);
	cout<<ans<<ln;
	return 0;
}