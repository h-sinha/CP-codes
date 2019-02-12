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
const int L=4e5+7;
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m = 1e9+7)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
int size_of_base;
ll MOD= 1e9 + 7;
std::vector<int> prime;
std::vector<pii> seg(4*L),lazy(4*L);
std::vector<ll> mask(302), baseArray(L);
void build(int start = 1, int end = size_of_base, int index = 1)
{
	lazy[index].F = 1;
	lazy[index].S = 0;
	if( start == end )
	{
		seg[index].F = baseArray[start];
		seg[index].S = mask[baseArray[start]];
		return;
	}
	int mid = (start + end)/2;
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);
	seg[index].F = (seg[2*index].F * seg[2*index + 1].F)%MOD;
	seg[index].S = (seg[2*index].S | seg[2*index + 1].S);
	return;
}
void lazyUpdate(int start, int end, int index)
{
	if(lazy[index].F != 1)
	{
		seg[index].F = (seg[index].F * fastexpo(lazy[index].F, end - start + 1)%MOD )%MOD;
		seg[index].S = (seg[index].S | lazy[index].S);
		if(start != end)
		{
			lazy[2*index].F = (lazy[2*index].F * lazy[index].F)%MOD;
			lazy[2*index].S = (lazy[2*index].S | lazy[index].S);
			lazy[2*index + 1].F = (lazy[2*index + 1].F * lazy[index].F)%MOD;
			lazy[2*index + 1].S = (lazy[2*index + 1].S | lazy[index].S);
		}
		lazy[index].F = 1;
		lazy[index].S = 0;
	}
	return;
}
void updateRange(int l, int r, ll value, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate(start, end, index);
	if(r < start || l > end || start > end )return;
	if( l <= start && r >= end )
	{
		seg[index].F = (seg[index].F * fastexpo(value, end - start + 1)%MOD)%MOD;
		seg[index].S = (seg[index].S | mask[value]);
		if(start != end)
		{
			lazy[2*index].F = (lazy[2*index].F * value)%MOD;
			lazy[2*index].S = (lazy[2*index].S | mask[value]);
			lazy[2*index + 1].F = (lazy[2*index + 1].F * value)%MOD;
			lazy[2*index + 1].S = (lazy[2*index + 1].S | mask[value]);
		}
		return;
	}
	int mid = (start + end)/2;
	updateRange(l, r, value, start, mid, 2*index );
	updateRange(l, r, value, mid+1, end, 2*index + 1);
	seg[index].F = (seg[2*index].F * seg[2*index + 1].F)%MOD ;
	seg[index].S = (seg[2*index].S | seg[2*index + 1].S) ;
	return;
}
pii query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate(start, end, index);
	if( start > r || end < l || start > end)
		return mp(1, 0);
	if(start >= l && end <= r)
		return seg[index];
	int mid = (start + end)/2;
	pii query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	return mp((query_left.F * query_right.F)%MOD, query_left.S|query_right.S); ;
}
void solve(ll prod, ll msk)
{
	ll num = prod, deno = 1;
	int idx = 0;
	while(msk > 0)
	{
		if(msk & 1)
		{
			num = (num * (prime[idx] - 1) )%MOD;
			deno = (deno * prime[idx])%MOD;
		}
		msk >>= 1;
		idx++;
	}
	deno = fastexpo(deno, MOD - 2)%MOD;
	cout<<(num*deno)%MOD<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int operations, idx, value, l, r, pr;
	string type;
	cin >> size_of_base >> operations;
	FOR(i,1,size_of_base+1)
		cin >> baseArray[i];
	FOR(i,2,300)
	{
		pr = 0;
		FOR(j,2,i)
		{
			if(i%j == 0)
			{
				pr=1;
				break;
			}
		}
		if(!pr)prime.pb(i);
	}
	FOR(i,2,300)
	{
		FOR(j,0,sz(prime))
		{
			if(i % prime[j] == 0)
				mask[i] = mask[i] + (1LL<<j);
		}
	}
	build();
	pii qq;
	while( operations-- )
	{
		cin >> type;
		if( type[0] == 'M' )
		{
			cin >> l >> r >> value;
			updateRange(l, r, value);
		}
		else if( type[0] == 'T' )
		{
			cin >> l >> r;
			qq = query(l, r);
			solve(qq.F, qq.S);
		}
	}
	return 0;
}