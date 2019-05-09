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
#define pii pair<int,int>
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
std::vector<int> v[L][2];
int cur_parent, parent[L][2], visit[L][2];
ll co, counter[L][2];
void dfs(int vertex, int _parent, int flag)
{
	visit[vertex][flag] = 1;
	co++;
	parent[vertex][flag] = cur_parent;
	trace(v[vertex][flag], x)
	{
		if(x != _parent)
			dfs(x, vertex, flag);
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, a, b , c;
	 	ll ans = 0;
	 	cin >> n;
	 	FOR(i,0,n-1)
	 	{
	 		cin >> a >> b >> c;
	 		if(c == 0)
	 		{
	 			v[a][0].pb(b);
	 			v[b][0].pb(a);
	 		}
	 		else
	 		{
	 			v[a][1].pb(b);
	 			v[b][1].pb(a);
	 		}
	 	}
	 	FOR(i,1,n+1)
	 	{
	 		if(!visit[i][0])
	 		{
	 			co = 0, cur_parent = i;
		 		dfs(i, -1, 0);
		 		counter[cur_parent][0] = co;
		 		ans += (co * (co - 1));
	 		}
	 		if(!visit[i][1])
	 		{
	 			co = 0, cur_parent = i;
		 		dfs(i, -1, 1);
		 		counter[cur_parent][1] = co;
		 		ans += (co * (co - 1));
	 		}
	 	}
	 	FOR(i,1,n+1)
	 	{
	 		if(parent[i][0] == 0 ||parent[i][1] == 0)continue;
	 		ans += ((counter[parent[i][0]][0] - 1) * (counter[parent[i][1]][1] - 1));
	 	}
	 	cout<<ans;
		return 0;
}