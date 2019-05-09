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
const int L=2e5+7;
std::vector<int> org[L],rev[L], parent(L);
stack <int> STACK;
std::vector<bool> visit(L),visit1(L);
int cur_parent;
std::vector<int> ans;
set<int>deg[L];
void dfs(int vertex)
{
	if(visit[vertex])return;
	visit[vertex]=1;
	trace(org[vertex],x)
		dfs(x);
	STACK.push(vertex);
	return;
}
void component(int vertex)
{

	if(visit1[vertex])return;
	parent[vertex] = cur_parent;
	visit1[vertex]=1;
	trace(rev[vertex],x)
		component(x);
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int a,b,n,m,cur;
	 	// n vertices m edges
	 	cin>>n>>m;
	 	while(m--)
	 	{
	 		cin>>a>>b;
	 		org[a].pb(b);
	 		rev[b].pb(a);
	 	}
	 	// push to stack
	 	FOR(i,1,n+1)
	 		if(!visit[i])
	 			dfs(i);
	 	// print scc
	 		std::vector<int> check;
	 	while(!STACK.empty())
	 	{
	 		cur=STACK.top();
	 		STACK.pop();
	 		if(!visit1[cur])
	 		{
	 			cur_parent = cur;
	 			check.pb(cur);
	 			component(cur);
	 		}
	 	}
	 	FOR(i,1,n+1)
	 	{
	 		trace(rev[i],x)
	 		{
	 			if(parent[i] == parent[x])continue;
	 			deg[parent[x]].insert(parent[i]);
	 		}
	 	}
	 	int comp = -1, co = 0;
	 	trace(check, x)
	 	{
	 		if(sz(deg[x]) == 0)
	 		{
	 			co++;
	 			comp = x;
	 		}
	 	}
	 	if(co != 1)cout<<"0\n";
	 	else
	 	{
	 		FOR(i,1,n+1)
	 		{
	 			if(parent[i] == comp)ans.pb(i);
	 		}
	 		cout<<sz(ans)<<ln;
	 		trace(ans, x)cout<<x<<" ";
	 	}
		return 0;
}