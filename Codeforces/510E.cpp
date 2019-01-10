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
#define sz(a)	int(a.size())
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

const int L=210;
struct node
{
	int to, idx;
	int flow, capacity;
};
std::vector<node> v[L];
std::vector<int> ptr(L), dist(L), match[L], ans[L];
void addEdge(int s, int t, int capacity)
{
	node a = {t, sz(v[t]), 0, capacity};
	node b = {s, sz(v[s]), 0, capacity};
	v[s].pb(a);
	v[t].pb(b);
}
int dfs(int vertex, int flow, int dest)
{
	if(vertex == dest)return flow;
	int df;
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
bool bfs(int src,int  dest, int number_of_nodes)
{
	fill(dist.begin(), dist.begin() + number_of_nodes + 1, -1);
	int tmp;
	queue<int>q;
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
ll maxFlow(int source, int destination, int number_of_nodes)
{
	if(source == destination)return -1;
	ll ans = 0, delta;
	while(bfs(source, destination, number_of_nodes))
	{
		fill(ptr.begin(), ptr.begin() + number_of_nodes, 0);
		while(delta = dfs(source, INT_MAX, destination))
		{
			ans += delta;
		}
	}
	return ans;
}
bool prime[100002], done[L];
void pre()
{
	prime[0] = prime[1] = 1;
	FOR(i,2,100000)
	{
		if(prime[i])continue;
		for (int j = 2*i; j <= 100000; j += i)
		{
			prime[j] = 1;
		}
	}
}
int a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin >> n;
	 	std::vector<int> e,o;
	 	FOR(i,1,n+1)
	 	{
	 		cin >> a[i];
	 		if(a[i]&1)o.pb(i);
	 		else e.pb(i);
	 	}
	 	if(sz(e) != sz(o))
	 	{
	 		cout<<"Impossible";
	 		return 0;
	 	}
	 	pre();
	 	trace(o,x)
	 	{
	 		addEdge(0, x, 2);
	 		trace(e,y)
	 		{
	 			if(!prime[a[x] + a[y]])addEdge(x, y, 1);
	 		}
	 	}
	 	trace(e, y)addEdge(y, 201, 2);
	 	int tmp = maxFlow(0,201,201);
		if(tmp != 2*sz(e))cout<<"Impossible\n";
		else 
		{
			trace(o,x)
			{
				trace(v[x], y)
				{
					if(y.flow == 1)
					{
						match[x].pb(y.to);
						match[y.to].pb(x);
					}
				}
			}
			int cur, prev, tmp,co = 0;
			FOR(x,1,n+1)
			{
				if(done[x])continue;
				done[x] = 1;
				cur = match[x][0], prev = x;
				ans[co].pb(x);
				ans[co].pb(cur);
				done[cur] = 1;
				while(1)
				{
					tmp = cur;
					if(match[cur][0] == prev)cur = match[cur][1];
					else cur = match[cur][0];
					prev = tmp;
					done[cur] = 1;
					ans[co].pb(cur);
					if(cur == match[x][1])break;
				}
				co++;
			}
			cout<<co<<ln;
			FOR(i,0,co)
			{
				cout<<sz(ans[i])<<" ";
				trace(ans[i], x)cout<<x<<" ";
				cout<<ln;
			}
		}		
		return 0;
}