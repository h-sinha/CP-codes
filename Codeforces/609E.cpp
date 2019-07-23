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

const int L=2e5+7;
struct node
{
	int a, b;
	ll wt;
	int idx;
};
bool comp(node x, node y)
{
	if(x.wt == y.wt)return x.idx < y.idx;
	return x.wt < y.wt;
}
int parent[L], children[L];
std::vector<pii> adj[L];
int find(int x)
{
	if(x == parent[x])return x;
	return parent[x] = find(parent[x]);
}
void merge(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if(children[pa] > children[pb])
	{
		parent[pa] = pb;
		children[pb] += children[pa];
	}
	else
	{
		parent[pb] = pa;
		children[pa] += children[pb];	
	}
}
std::vector<int> ans(L, -1);
int pr[L][22], level[L], mx[L][22];
void dfs(int vertex, int _parent = -1, int depth = 0)
{
	pr[vertex][0] = _parent;
	level[vertex] = depth;
	trace(adj[vertex], x)
	{
		if(x.F != _parent)
		{
			mx[x.F][0] = x.S;
			dfs(x.F, vertex, depth + 1);
		}
	}
}
int lca(int a,int b)
{
	if(level[a]>level[b])swap(a,b);
	int dist=level[b]-level[a];
	int index=0, ret = 0;
	while(dist>0)
	{
		if(dist&1)
		{
			ret = max(ret, mx[b][index]);
			b=pr[b][index];
		}
		dist>>=1;index++;
	}
	
	RFOR(i,18,0)
	{
		if(pr[a][i]!=-1 && pr[a][i]!=pr[b][i])
		{
			ret = max(ret, mx[a][i]);
			ret = max(ret, mx[b][i]);
			a=pr[a][i];
			b=pr[b][i];
		}
	}
	if(a==b)return ret;
	ret = max(ret, mx[a][0]);
	ret = max(ret, mx[b][0]);
	return ret;	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, pa, pb, a, b;
	ll c;
	cin >> n >> m;
	std::vector<node> v;
	FOR(i,0,m)
	{
		cin >> a >> b >> c;
		v.pb(node{a,b,c,i});
	}
	sort(all(v), comp);
	FOR(i,1,n+1)parent[i] = i, children[i] = 1;
	ll mst = 0;
	trace(v, x)
	{
		pa = find(x.a);
		pb = find(x.b);
		if(pa == pb)continue;
		merge(x.a, x.b);
		ans[x.idx] = 0;
		mst += x.wt;
		adj[x.a].pb({x.b, x.wt});
		adj[x.b].pb({x.a, x.wt});
	}
	FOR(i,1,n+1)FOR(j,0,20)pr[i][j] = -1;
	dfs(1);
	FOR(i,1,20)
	{
		FOR(j,1,n+1)
		{
			if(pr[j][i-1] != -1)
			{
				mx[j][i] = max(mx[j][i-1],mx[pr[j][i-1]][i-1]);
				pr[j][i] = pr[pr[j][i-1]][i-1];
			}
		}
	}
	trace(v, x)
	{
		if(ans[x.idx] != -1)continue;
		ans[x.idx] = x.wt - lca(x.a, x.b);
	}
	FOR(i,0,m)cout << ans[i] + mst << ln;
	return 0;
}