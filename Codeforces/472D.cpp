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
const int L=2002;
ll mat[L][L], rootDist[L];
std::vector<pii> adj[L];
int level[L], parent[L][30], done[L], component[L];
struct node
{
	int u,v;
	ll wt;
};
bool comparator(node x, node y)
{
	return x.wt<y.wt;
}

void dfs(int vertex,int pr,int lvl, ll sofar)
{
	parent[vertex][0]=pr;
	level[vertex]=lvl;
	rootDist[vertex] = sofar;
	trace(adj[vertex], x)
		if(x.F!=pr)
			dfs(x.F,vertex,lvl+1, sofar+x.S);
}
int lca(int a,int b)
{
	if(level[a]>level[b])swap(a,b);
	int dist=level[b]-level[a];
	int index=0;
	while(dist>0)
	{
		if(dist&1){b=parent[b][index];}
		dist>>=1;index++;
	}
	
	RFOR(i,18,0)
	{
		if(parent[a][i]!=-1 && parent[a][i]!=parent[b][i])
		{
			a=parent[a][i];
			b=parent[b][i];
		}
	}
	if(a==b)return a;
	return parent[a][0];
}
ll findDist(ll u, ll v)
{
	return rootDist[u] + rootDist[v] - 2*rootDist[lca(u,v)];
}
int findcomponent(int i)
{
	if(component[i]==i)return i;
	return component[i] = findcomponent(component[i]);
}
void merge(int i, int j)
{
	int pi = findcomponent(i), pj = findcomponent(j);
	component[pj] = pi;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, edges = 0;
	 	cin >> n;
	 	FOR(i,1,n+1)FOR(j,1,n+1)cin >> mat[i][j];
		FOR(i,1,n+1)
		{
			if(mat[i][i])
			{
				cout<<"NO";
				return 0;
			}
		}
		std::vector<node> v;
		node temp;
		FOR(i,1,n+1)
		{
			FOR(j,i+1,n+1)
			{
				if(mat[i][j] != mat[j][i])
				{
					cout<<"NO";
					return 0;
				}
				if(mat[i][j])
					v.pb({i, j, mat[i][j]});
			}

		}
		sort(all(v),comparator);
		FOR(i,1,n+1)component[i]=i;
		trace(v, x)
		{
			if(findcomponent(x.u) == findcomponent(x.v))continue;
			adj[x.u].pb(mp(x.v,x.wt));
			adj[x.v].pb(mp(x.u,x.wt));
			done[x.u] = done[x.v] = 1;
			edges++;
			merge(x.u, x.v);
		}
		if(edges != n-1)
		{
			cout<<"NO";
			return 0;
		}
		dfs(1,-1,0, 0);
		FOR(j,1,19)
		 	FOR(i,1,n+1)
		 		if(parent[i][j-1]!=-1)
	 				parent[i][j]=parent[parent[i][j-1]][j-1];

		FOR(i,1,n+1)
		{
			FOR(j,i+1,n+1)
			{
				if(findDist(i,j) != mat[i][j])
				{
					cout<<"NO";
					return 0;
				}
			}
		}
		cout<<"YES";
		return 0;
}