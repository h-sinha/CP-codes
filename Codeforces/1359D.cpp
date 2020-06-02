#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define rall(c) c.rbegin(), c.rend()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
#define init(a, x) memset(a,x,sizeof(a))
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
const int L=1e5+7; 
ll baseArray[L], seg[4*L],size_of_base, inf = INT_MAX;
ll combine(ll a, ll b)
{
	return min(a,b);
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
ll seg1[4*L], inf1 = INT_MIN;
ll combine1(ll a, ll b)
{
	return max(a,b);
}
void build1(int start = 1, int end = size_of_base, int index = 1)
{
	if( start == end )
	{
		seg1[index] = baseArray[start];
		return;
	}
	int mid = (start + end)/2;
	build1(start, mid, 2*index);
	build1(mid+1, end, 2*index + 1);
	seg1[index] = combine1( seg1[ 2*index ] , seg1[ 2*index + 1] );
	return;
}
ll query1(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	if( start > r || end < l )return inf1;
	if(start >= l && end <= r)
	{
		return seg1[index];
	}
	int mid = (start + end)/2;
	ll query_left, query_right;
	query_left = query1(l, r, start, mid, 2*index );
	query_right = query1(l, r, mid+1, end, 2*index + 1);
	return combine1(query_left, query_right);
}
ll dp[L], dp1[L], a[L];
void fff()
{
	int n;
	cin >> n;
	size_of_base = n;
	FOR(i,1,n+1)cin >> a[i];
	FOR(i,1,n+1)baseArray[i] = a[i] + baseArray[i-1];
	build1();
	build();
	stack<int> S; 
    FOR(i,1,n+1)
    { 
    	dp1[i] = n+1;
        while (!S.empty() && a[S.top()] <= a[i]) 
            S.pop(); 
        if (!S.empty())dp[i] = S.top();
        S.push(i); 
    } 
    while(!S.empty())S.pop();
    RFOR(i,n,1)
    { 
        while (!S.empty() && a[S.top()] <= a[i]) 
            S.pop(); 
        if (!S.empty())dp1[i] = S.top();
        S.push(i); 
    } 
	int l = 0, r = 0;
	ll ans = 0, bf, rt, s1, s2;
	FOR(i,1,n+1)
	{
		l = dp[i];
		r = dp1[i];
		bf = query(l,i-1);
		rt = query1(i+1,r-1);
		// debug(i,a[i],l,r,bf,baseArray[i-1], rt,baseArray[i]);
		if(l == 0 &&  bf > 0)bf= 0;
		if(bf == INT_MAX)
		{
			if(rt == INT_MIN)continue;
			ans =max(ans,rt- baseArray[i]);
		}
		else if(rt == INT_MIN)
		{
			ans =max(ans,baseArray[i-1]-bf);
		}
		else
		{
			if(baseArray[i-1] - bf < 0)s1 = 0;
			else s1 = baseArray[i-1] - bf;
			if(rt - baseArray[i] < 0)s2 = 0;
			else s2 = rt - baseArray[i];
			ans =max(ans,s1+s2);
		}
	}
	cout<<ans<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}