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
const int L=1e6+7;
map<ll,ll> counter;
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
ll baseArray[L], seg[4*L],size_of_base, inf;
ll combine(ll a, ll b)
{
	return (a^b);
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
	seg[index] = combine( seg[ 2*index ] , seg[ 2*index + 1] );
	return;
}
void update(int updateindex, int start = 1, int end = size_of_base, int index = 1)
{
	if(updateindex < start || updateindex > end)return;
	if( start == end && updateindex == start )
	{
		seg[index] = baseArray[start];
		return;
	}
	int mid = (start + end)/2;
	update(updateindex, start, mid, 2*index );
	update(updateindex, mid+1, end, 2*index + 1);
	seg[index] = combine( seg[ 2*index ] , seg[ 2*index + 1] );
	return;
}
ll query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	if( start > r || end < l )return inf;
	if(start >= l && end <= r)
	{
		return seg[index];
	}
	int mid = (start + end)/2;
	ll query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	return combine(query_left, query_right);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int operations, idx, value, l, r, type;
	cin>>size_of_base>>operations;
	inf = 0;
	for (int i = 1; i <= size_of_base; ++i)
		cin>>baseArray[i];
	
	build();
	while( operations-- )
	{
		cin>>type;
		if( type == 2 )
		{
			cin >> l >> r;
			cout<<query(l, r)<<ln;
		}
		else if( type == 1 )
		{
			cin >> idx >> value;
			baseArray[idx] ^= value;
			update(idx);
		}
	}
	return 0;
}
