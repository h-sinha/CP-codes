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

const int L=1002;
std::vector<int> v[L];
int mx = INT_MIN, start = -1;
std::vector<bool> visit(L);
void dfs(int vertex, int parent = -1, int _depth = 0)
{
	visit[vertex] = 1;
	if(_depth > mx)
	{
		mx = _depth;
		start = vertex;
	}
	trace(v[vertex], x)
	{
		if(x != parent)
			dfs(x, vertex, _depth + 1);
	}
}
set<int>depth[L];
void findRoot(int vertex, int parent = -1, int _depth = 0)
{
	depth[_depth].insert(vertex);
	mx = max(mx, _depth);
	trace(v[vertex], x)
	{
		if(x != parent)
			findRoot(x, vertex, _depth + 1);
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
	 	std::vector<int> root;
	 	FOR(i,1,n+1)
	 	{
	 		if(!visit[i])
	 		{
	 			FOR(j,0,n+1)depth[j].clear();
	 			mx = INT_MIN;
	 			start = -1;
	 			dfs(i);
	 			mx = INT_MIN;
	 			findRoot(start);
	 			root.pb(*(depth[mx/2].begin()));
	 		}
	 	}
	 	int id = root[0];
	 	std::vector<pii> ans;
	 	trace(root, x)
	 	{
	 		if(x == id)continue;
	 		v[x].pb(id);
	 		v[id].pb(x);
	 		ans.pb(mp(x, id));
	 	}
	 	mx = INT_MIN;
	 	start = -1;
	 	dfs(1);
	 	mx = INT_MIN;
	 	findRoot(start);
	 	cout<<mx<<ln;
	 	trace(ans, x)cout<<x.F<<" "<<x.S<<ln;
		return 0;
}