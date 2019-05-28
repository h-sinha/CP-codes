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

const int L=305;
set<int>subtree[L];
std::vector<int> ans, v[L];
int order[L], cur = 0;
void dfs(int vertex, int parent)
{
	subtree[vertex].insert(vertex);
	trace(v[vertex], x)
	{
		if(x!=parent)
		{
			dfs(x, vertex);
			trace(subtree[x], y)subtree[vertex].insert(y);
		}
	}
}
void find(int vertex, int parent)
{
	ans.pb(vertex);
	if(vertex == order[cur])
	{
		cur++;
		return;
	}
	int f = 1;
	while(f)
	{
		f = 0;
		trace(v[vertex], x)
		{
			if(x != parent && subtree[x].find(order[cur])!=subtree[x].end())
			{
				find(x, vertex);
				ans.pb(vertex);				
				f = 1;
			}
		}
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, a, b;
	 	cin >> n;
	 	FOR(i,0,n-1)
	 	{
	 		cin >> a >> b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	int k = 0;
	 	FOR(i,2,n+1)
	 	{
	 		if(sz(v[i]) == 1)k++;
	 	}
	 	FOR(i,0,k)cin >> order[i];
	 	dfs(1,-1);
		find(1, -1);
		if(sz(ans)!=2*n-1)cout<<"-1";
		else trace(ans,x)cout<<x<<" ";
		return 0;
}