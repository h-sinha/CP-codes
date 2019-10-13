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
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=1e6+7;
int rep[L], visit[L], root[L], dist[L], depth[L], diameter[L];
std::vector<int> v[L];
int mx = -1, node;
void dfs1(int vertex, int parent = -1, int l = 0)
{
	visit[vertex] = 1;
	if(l > mx)
	{
		mx = l;
		node = vertex;
	}
	trace(v[vertex], x)
	{
		if(x != parent)
		{
			dfs1(x, vertex, l + 1);
		}
	}
}
set<int>SET;
void dfs2(int vertex, int parent = -1, int l = 0)
{
	dist[vertex] = l;
	mx = max(mx, l);
	SET.insert(vertex);
	trace(v[vertex], x)
	{
		if(x != parent)
		{
			dfs2(x, vertex, l + 1);
		}
	}
}
int ans = 0;
int merge(pii x, pii y)
{
	if(depth[x.S] > depth[y.S])
	{
		rep[y.S] = x.S;
		diameter[x.S] = depth[x.S] + depth[y.S] + 1;
		ans = max(ans, diameter[x.S]);
		return x.S;
	}
	else
	{

		rep[x.S] = y.S;
		diameter[y.S] = depth[y.S] + depth[x.S] + 1;
		if(depth[x.S] == depth[y.S])
		{
			depth[y.S] = depth[y.S] + 1;
		}
		ans = max(ans, diameter[y.S]);
		return y.S;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	cin >> n >> m;
	FOR(i,0,m)
	{
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	FOR(i,0,n)
	{
		if(!visit[i])
		{
			mx = -1;
			dfs1(i);
			mx = -1;
			SET.clear();
			dfs2(node);
			int cur;
			trace(SET,x)
			{
				if(dist[x] == mx/2)cur = x;
			}
			ans = max(ans,mx);
			diameter[cur] = mx;
			trace(SET,x)
			{
				rep[x] = cur;
				depth[x] = (mx+1)/2;
			}
		}
	}
	set<pii>ro;
	pii cur1, cur2;
	FOR(i,0,n)ro.insert({-depth[i], rep[i]});
	int cur;
	while(sz(ro)>1)
	{
		cur1 = *ro.begin();
		ro.erase(ro.begin());
		cur2 = *ro.begin();
		ro.erase(ro.begin());
		cur = merge(cur1, cur2);
		ro.insert({-depth[cur], cur});
	}
	cout<<ans;
	return 0;
}