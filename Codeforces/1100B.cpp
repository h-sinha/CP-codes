#include<bits/stdc++.h>
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
#else
#define debug(...)
#endif
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
ll counter[L];
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
	seg[index] = min(seg[2*index] , seg[2*index + 1]);
	return;
}
void lazyUpdate(int start, int end, int index)
{
	if(lazy[index] != 0)
	{
		seg[index] += lazy[index];
		if(start != end)
		{
			lazy[2*index] += lazy[index];
			lazy[(2*index) + 1] += lazy[index];
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
		seg[index] += value;
		if(start != end)
		{
			lazy[2*index] += value;
			lazy[2*index + 1] += value;
		}
		return;
	}
	int mid = (start + end)/2;
	updateRange(l, r, value, start, mid, 2*index );
	updateRange(l, r, value, mid+1, end, 2*index + 1);
	seg[index] = min(seg[2*index] , seg[2*index + 1]) ;
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
	return min(query_left , query_right);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll operations, idx, value, l, r;
	char type;
	cin >> size_of_base >> operations;
	FOR(i,0,operations)
	{
		cin >> l;
		counter[l]++;
		updateRange(l,l,1);
		if(query(1,size_of_base) == 1)
		{
			cout<<"1";
			updateRange(1,size_of_base,-1);
		}
		else cout<<"0";
	}
	return 0;
}