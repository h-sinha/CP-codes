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
std::vector<int> v[L];
int parent[L][30], depth[L];
void dfs(int vertex, int pr = -1, int dpt = 0)
{
	depth[vertex] = dpt;
	parent[vertex][0] = pr;
	trace(v[vertex], x)
	{
		if(x != pr)
			dfs(x, vertex, dpt + 1);
	}
}
int lca(int a,int b)
{
	if(depth[a]>depth[b])swap(a,b);
	int dist=depth[b]-depth[a];
	FOR(i,0,22)
	{
		if((dist>>i)&1)b = parent[b][i];
	}
	RFOR(i,22,0)
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
int find(int b, int dist)
{
	FOR(i,0,22)
	{
		if((dist>>i)&1)b = parent[b][i];
	}
	return b;
}
void fff()
{
	int n, a, b, c, q, l;
	cin >> n;
	FOR(i,0,n-1)
	{
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}	
	init(parent, -1);
	dfs(1);
	FOR(j,1,24)
		FOR(i,1,n+1)
			if(parent[i][j-1] != -1)
				parent[i][j] = parent[parent[i][j-1]][j-1];
	cin >> q;
	int up, down;
	while(q--)
	{
		cin >> a >> b >> c;
		l = lca(a, b);
		up = depth[a] - depth[l];
		down = depth[b] - depth[l];
		if(up >= c)cout << find(a, c) << ln;
		else if(up + down <= c)cout << b << ln;
		else cout << find(b, up + down - c) << ln;
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