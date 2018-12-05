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
#define sz(a)	int(a.size())
#define F first
#define S second
#define aint(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<int,int>
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=5e5+7;
int size_of_base;
std::vector<int> baseArray(L),seg(4*L),lazy(4*L,-1);
std::vector<int> v[L];
void lazyUpdate(int start, int end, int index)
{
	if(lazy[index] != -1)
	{
		seg[index] = lazy[index];
		if(start != end)
		{
			lazy[2*index] = lazy[index];
			lazy[(2*index) + 1] = lazy[index];
		}
		lazy[index] = -1;
	}
	return;
}
void updateRange(int l, int r, int value, int start = 1, int end = size_of_base, int index = 1)
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
	seg[index] = min(seg[2*index], seg[2*index + 1]) ;
	return;
}
void update(int updateindex, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate(start, end, index);
	if(updateindex < start || updateindex > end)return;
	if( start == end && updateindex == start )
	{
		seg[index] = 0;
		return;
	}
	int mid = (start + end)/2;
	update(updateindex, start, mid, 2*index );
	update(updateindex, mid+1, end, 2*index + 1);
	seg[index] = min( seg[ 2*index ] , seg[ 2*index + 1] );
	return;
}
int query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate(start, end, index);
	if( start > r || end < l || start > end)
		return 1;
	if(start >= l && end <= r)
		return seg[index];
	int mid = (start + end)/2, query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	return min(query_left, query_right);
}
int tim = 1, posinbase[L], start[L], ending[L], pr[L];
void dfs(int vertex, int parent)
{
	posinbase[vertex] = tim;
	pr[vertex] = parent;
	start[vertex] = tim++;
	trace(v[vertex], x)
		if(x!=parent)dfs(x, vertex);
	ending[vertex] = tim-1;
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, type, vertex, operations, tmp, tmp1;
	cin >> size_of_base;
	FOR(i,0,size_of_base-1)
	{
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1,-1);
	cin >> operations;
	while(operations--)
	{
		cin >> type >> vertex;
		if(type == 1)
		{
			if(pr[vertex] != -1)
			{
				tmp = query(start[vertex], ending[vertex]);
				if(tmp == 0 )
					updateRange(start[pr[vertex]],start[pr[vertex]], 0);
			}
			updateRange(start[vertex], ending[vertex], 1);
		}
		else if (type == 2)
			update(start[vertex]);
		else 
			cout<<query(start[vertex], ending[vertex])<<ln;
	}
	return 0;
}