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
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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
map<ll,ll> counter;
const ll L = 2e5+7;
ll a[L];
ll baseArray[L], seg[4*L],size_of_base, inf;
ll baseArray1[L], seg1[4*L],size_of_base1;
ll combine(ll a, ll b)
{
	return (a+b);
}
void build(ll start = 1, ll end = size_of_base, ll index = 1)
{
	if( start == end )
	{
		seg[index] = baseArray[start];
		return;
	}
	ll mid = (start + end)/2;
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);
	seg[index] = combine( seg[ 2*index ] , seg[ 2*index + 1] );
	return;
}
void update(ll updateindex, ll start = 1, ll end = size_of_base, ll index = 1)
{
	if(updateindex < start || updateindex > end)return;
	if( start == end && updateindex == start )
	{
		seg[index] = baseArray[start];
		return;
	}
	ll mid = (start + end)/2;
	update(updateindex, start, mid, 2*index );
	update(updateindex, mid+1, end, 2*index + 1);
	seg[index] = combine( seg[ 2*index ] , seg[ 2*index + 1] );
	return;
}
ll query(ll l, ll r, ll start = 1, ll end = size_of_base, ll index = 1)
{
	if( start > r || end < l )return inf;
	if(start >= l && end <= r)
	{
		return seg[index];
	}
	ll mid = (start + end)/2;
	ll query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	return combine(query_left, query_right);
}
void build1(ll start = 1, ll end = size_of_base, ll index = 1)
{
	if( start == end )
	{
		seg1[index] = baseArray1[start];
		return;
	}
	ll mid = (start + end)/2;
	build1(start, mid, 2*index);
	build1(mid+1, end, 2*index + 1);
	seg1[index] = combine( seg1[ 2*index ] , seg1[ 2*index + 1] );
	return;
}
void update1(ll updateindex, ll start = 1, ll end = size_of_base, ll index = 1)
{
	if(updateindex < start || updateindex > end)return;
	if( start == end && updateindex == start )
	{
		seg1[index] = baseArray1[start];
		return;
	}
	ll mid = (start + end)/2;
	update1(updateindex, start, mid, 2*index );
	update1(updateindex, mid+1, end, 2*index + 1);
	seg1[index] = combine( seg1[ 2*index ] , seg1[ 2*index + 1] );
	return;
}
ll query1(ll l, ll r, ll start = 1, ll end = size_of_base, ll index = 1)
{
	if( start > r || end < l )return inf;
	if(start >= l && end <= r)
	{
		return seg1[index];
	}
	ll mid = (start + end)/2;
	ll query_left, query_right;
	query_left = query1(l, r, start, mid, 2*index );
	query_right = query1(l, r, mid+1, end, 2*index + 1);
	return combine(query_left, query_right);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	char type;
	cin >> t;
	ll q1,q2,l,r;
	FOR(qq,1,t+1)
	{
		ll n,q;
		cin >> n >> q;
		size_of_base = n;
		size_of_base1 = n;
		ll ans = 0;
		FOR(i,1,n+1)
		{
			cin >> a[i];
			if(i&1)
			baseArray[i] = a[i]*(-i),baseArray1[i] = -a[i];
			else
			baseArray[i] = a[i]*(i),baseArray1[i] = a[i];
		}
		build();
		build1();
		while(q--)
		{
			cin >> type >> l>>r;
			if(type == 'U')
			{
				if(l&1)
				baseArray[l] = r*(-l),baseArray1[l] = -r;
				else
				baseArray[l] = r*l,baseArray1[l] = r;
				update(l);
				update1(l);
			}
			else
			{
				q1 = query(l,r);
				q2 = query1(l,r);
				q1 -= (q2*(l-1));
				if(l%2==0)ans+=q1;
				else ans-=q1;
			}
		}
		cout<<"Case #"<<qq<<": "<<ans<<ln;
	}
	return 0;
}
