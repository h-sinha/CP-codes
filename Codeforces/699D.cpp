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

const int L=2e5+7;
map<ll,ll> counter;
int co, ans[L], org[L], st;
std::vector<bool> visit(L), white(L);
std::vector<int> v[L];
void dfs(int vertex, int parent = -1)
{
	if(white[vertex])
	{
		ans[vertex] = st;
		if(st == 0){ans[vertex] = vertex;st = vertex;}
		return;

	}
	if(visit[vertex])return;
	visit[vertex] = 1;
	white[vertex] = 1;
	int f =0;
	trace(v[vertex], x)
	{
		if(x != parent)
			dfs(x, vertex);
		else if(f)
		{
			ans[vertex] = st;
			if(st == 0){ans[vertex] = vertex;st = vertex;}
		}
		else f = 1;
	}
	white[vertex] = 0;
}

int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, a;
	 	cin >> n;
	 	FOR(i,1,n+1)
	 	{
	 		cin >> a;
	 		if(i != a)
	 		{
	 			v[i].pb(a);
	 			v[a].pb(i);
	 		}
	 		if(a == i)st = i;
	 		org[i] = ans[i] = a;
	 	}
	 	FOR(i,1, n+1)
	 		if(org[i] == i)ans[i] = st;
	 	FOR(i,1,n+1)
	 		if(!visit[i])
	 			dfs(i);
	 	FOR(i,1,n+1)
	 		if(ans[i] != org[i])co++;
	 	cout<<co<<ln;
	 	FOR(i,1,n+1)cout<<ans[i]<<" ";
		return 0;
}