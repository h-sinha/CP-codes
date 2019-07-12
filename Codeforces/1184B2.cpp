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

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const ll L=5005;
struct node
{
	ll to, idx;
	ll flow, capacity;
};
std::vector<node> v[L];
std::vector<ll> ptr(L), dist(L);
ll dp[L][L], x[L], y[L], a[L], f[L], d[L];
void addEdge(ll s, ll t, ll capacity)
{
	node a = {t, sz(v[t]), 0, capacity};
	node b = {s, sz(v[s]), 0, capacity};
	v[s].pb(a);
	v[t].pb(b);
}
ll dfs(ll vertex, ll flow, ll dest)
{
	if(vertex == dest)return flow;
	ll df;
	node x;
	for(;ptr[vertex] < sz(v[vertex]);ptr[vertex]++)
	{
		x = v[vertex][ptr[vertex]];
		if(dist[x.to] == dist[vertex] + 1 && x.flow < x.capacity)
		{
			df = dfs(x.to, min(flow, x.capacity - x.flow), dest);
			if(df > 0)
			{
				v[vertex][ptr[vertex]].flow += df;
				v[x.to][x.idx].flow -= df;
				return df;
			}
		}
	}
	return 0;
}
bool bfs(ll src,ll  dest, ll number_of_nodes)
{
	fill(dist.begin(), dist.begin() + number_of_nodes + 1, -1);
	ll tmp;
	queue<ll>q;
	q.push(src);
	dist[src] = 0;
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		trace(v[tmp], x)
		{
			if(dist[x.to] == -1 && x.flow < x.capacity)
			{
				dist[x.to] = dist[tmp] + 1;
				q.push(x.to);
			}
		}
	}
	return dist[dest] == -1 ? 0 : 1; 
}
ll maxFlow(ll source, ll destination, ll number_of_nodes)
{
	if(source == destination)return -1;
	ll ans = 0, delta;
	while(bfs(source, destination, number_of_nodes))
	{
		fill(ptr.begin(), ptr.begin() + number_of_nodes, 0);
		while(delta = dfs(source, 1e15, destination))
		{
			ans += delta;
		}
	}
	return ans;
}
void floyd(ll n)
{
	FOR(i,1,n+1)
	{
		FOR(j,1,n+1)
		{
			FOR(k,1,n+1)
			{
				if(dp[j][k]>dp[j][i] + dp[i][k])
				{
					dp[j][k] = dp[j][i] + dp[i][k];
				}
			}
		}
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n, m, b ,c,s,k,h, l,r;
	 	cin >> n >> m;
	 	FOR(i,1,n+1)
	 	{
	 		FOR(j,1,n+1)
	 		{
	 			if(i!=j)dp[i][j] = 1e15;
	 		}
	 	}
	 	FOR(i,0,m)
	 	{
	 		cin >> l >> r ;
	 		dp[l][r] = 1;
	 		dp[r][l] = 1;
	 	}
	 	floyd(n);
	 	cin >> s >> b >> k >> h;
	 	FOR(i,1,s+1)
	 	{
	 		cin >> x[i] >> a[i] >> f[i];
	 		addEdge(0,i,1);
	 	}
	 	FOR(i,1,b+1)
	 	{
	 		cin >> y[i] >> d[i];
	 		addEdge(i + 1000,2005,1);
	 	}
	 	FOR(i,1,s+1)
	 	{

	 		FOR(j,1,b+1)
	 		{
	 			if(a[i] >= d[j] && f[i] >= dp[x[i]][y[j]])
	 			{
	 				addEdge(i, j+1000, 1);
	 			}
	 		}
	 	}
	 	ll cur = maxFlow(0,2005,2006);
	 	cout<<min(cur*k,s*h);
		return 0;
}