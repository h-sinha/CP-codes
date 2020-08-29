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
std::vector<pii> v[L];
int parent[L][23], depth[L], weight[L][25];
int cur, visit[L], comp[L];
void dfs(int vertex, int pr = -1, int dpt = 0, int prw = 1e9+1)
{
	depth[vertex] = dpt;
	parent[vertex][0] = pr;
	comp[vertex] = cur;
	visit[vertex] = 1;
	weight[vertex][0] = prw;
	trace(v[vertex], x)
	{
		if(x.F != pr)
			dfs(x.F, vertex, dpt + 1, x.S);
	}
}
int lca(int a,int b)
{
	if(depth[a]>depth[b])swap(a,b);
	int dist=depth[b]-depth[a], ans = 1e9 + 10;
	FOR(i,0,22)
	{
		if((dist>>i)&1)
		{
			ans = min(ans, weight[b][i]);
			b = parent[b][i];
		}
	}
	RFOR(i,22,0)
	{
		if(parent[a][i]!=-1 && parent[a][i]!=parent[b][i])
		{
			ans = min(ans, weight[a][i]);
			ans = min(ans, weight[b][i]);
			a=parent[a][i];
			b=parent[b][i];
		}
	}
	if(a==b)return ans;
	return min(ans, min(weight[a][0], weight[b][0]));
}
void fff()
{
	int n, m, a, b, c, q, l;
	cin >> n >> m;
	FOR(i,0,m)
	{
		cin >> a >> b >> c;
		v[a].pb({b,c});
		v[b].pb({a,c});
	}	
	FOR(i,0,n+1)
	{
		FOR(j,0,22)
		{
			parent[i][j] = -1;
			weight[i][j] = 1e9 + 10;
		}
	}	
	FOR(i,1,n+1)
	{
		if(!visit[i])
		{
			cur++;
			dfs(i);
		}
	}
	FOR(j,1,22)
	{
		FOR(i,1,n+1)
		{
			if(parent[i][j-1] != -1)
			{
				weight[i][j] = min(weight[i][j-1], weight[parent[i][j-1]][j-1]);
				parent[i][j] = parent[parent[i][j-1]][j-1];
			}
		}
	}
	cin >> q;
	while(q--)
	{
		cin >> a >> b;
		if(comp[a] != comp[b])cout << 0 << ln;
		else 
		{
			cout << lca(a, b) << ln;
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