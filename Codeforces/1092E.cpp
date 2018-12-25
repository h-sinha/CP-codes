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
std::vector<int> depth(L), depth1(L);
void dfs(int vertex, int parent = -1, int _depth = 0)
{
	visit[vertex] = 1;
	depth1[vertex] = _depth;
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
set<int>cur;
void findRoot(int vertex, int parent = -1, int _depth = 0)
{
	cur.insert(vertex);
	mx = max(mx, _depth);
	depth[vertex] = _depth;
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
	 	std::vector<pii> root;
	 	FOR(i,1,n+1)
	 	{
	 		if(!visit[i])
	 		{
	 			cur.clear();
	 			mx = INT_MIN;
	 			start = -1;
	 			dfs(i);
	 			mx = INT_MIN;
	 			findRoot(start);
	 			trace(cur, x)if(depth1[x] == mx/2 && depth[x] == mx - mx/2)start = x;
	 			root.pb(mp(mx, start));
	 		}

	 	}
	 	std::vector<pii> ans;
	 	sort(all(root));
	 	// trace(root,x )cout<<x.F<<" - "<<x.S<<ln;
	 	int st = root[sz(root) - 1].S;
	 	trace(root, x)
	 	{
	 		if(x.S == st)continue;
	 		v[x.S].pb(st);
	 		v[st].pb(x.S);
	 		ans.pb(mp(x.S, st));
	 	}
	 	mx = -1, start = -1;
	 	dfs(1);
	 	mx = -1;
	 	findRoot(start);
	 	cout<<mx<<ln;
	 	trace(ans, x)cout<<x.F<<" "<<x.S<<ln;
		return 0;
}