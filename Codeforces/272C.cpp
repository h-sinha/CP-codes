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
const int L=1e5+7;
ll size_of_base;
std::vector<ll> baseArray(L),seg(4*L),lazy(4*L);
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
	seg[index] = max(seg[2*index] , seg[2*index + 1]);
	return;
}
void lazyUpdate(int start, int end, int index)
{
	if(lazy[index] != 0)
	{
		seg[index] = max(seg[index], lazy[index]);
		if(start != end)
		{
			lazy[2*index] = max(lazy[2*index],lazy[index]);
			lazy[(2*index) + 1] =max(lazy[(2*index)+1], lazy[index]);
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
		seg[index] = value;
		if(start != end)
		{
			lazy[2*index] = value;
			lazy[2*index + 1] = value;
		}
		return;
	}
	int mid = (start + end)/2;
	updateRange(l, r, value, start, mid, 2*index );
	updateRange(l, r, value, mid+1, end, 2*index + 1);
	seg[index] = max(seg[2*index] , seg[2*index + 1]) ;
	return;
}
ll query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate(start, end, index);
	if( start > r || end < l || start > end)
		return INT_MIN;
	if(start >= l && end <= r)
		return seg[index];
	int mid = (start + end)/2;
	ll query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	return max(query_left , query_right);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll operations, idx, value, l, r, w ,h;
	cin >> size_of_base;
	for (ll i = 1; i <= size_of_base; ++i)
		cin >> baseArray[i];
	build();
	cin >> operations;
	while( operations-- )
	{
		cin >> w >> h;
		value = query(1,w);
		cout << value <<ln;
		updateRange(1, w,value+h);
	}
	return 0;
}