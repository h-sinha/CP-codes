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
const int L=3e5+7;
int depth[L], st[L], tim = 1, en[L];
ld baseArray[L], seg[4*L];
int size_of_base, inf;
std::vector<int> v[L];
ld combine(ld a, ld b)
{
	return (a+b);
}
void update(int updateindex, int start = 1, int end = size_of_base, int index = 1)
{
	if(updateindex < start || updateindex > end)return;
	if( start == end && updateindex == start )
	{
		seg[index] = log10(baseArray[start]);
		return;
	}
	int mid = (start + end)/2;
	update(updateindex, start, mid, 2*index );
	update(updateindex, mid+1, end, 2*index + 1);
	seg[index] = combine( seg[ 2*index ] , seg[ 2*index + 1] );
	return;
}
ld query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	if( start > r || end < l )return inf;
	if(start >= l && end <= r)
	{
		return seg[index];
	}
	int mid = (start + end)/2;
	ld query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	return combine(query_left, query_right);
}
void dfs(int vertex, int parent = -1)
{
	st[vertex] = tim;
	baseArray[tim] = 1;
	trace(v[vertex], x)
	{
		if(x != parent)
		{
			tim++;
			dfs(x, vertex);
		}
	}
	en[vertex] = tim;
}
void fff()
{
	int n, a, b;
	scanf("%d", &n);
	inf = 0;
	FOR(i,0,n-1)
	{
		scanf("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}	
	dfs(1);
	size_of_base = tim;
	int q, type;
	ld x1, x2;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&type,&a,&b);
		if(type == 1)
		{
			baseArray[st[a]] = b;
			update(st[a]);
		}
		else
		{
			x1 = query(st[a], en[a]);
			x2 = query(st[b], en[b]);
			if(x1-x2 >= 9)printf("1000000000\n");	
			else printf("%.100Lf\n",pow(10,x1-x2));
		}
	}
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