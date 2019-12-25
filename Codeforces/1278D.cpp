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
#define eb emplace_back
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

const int L=5e5+7;
std::vector<int> adj[L];
int a[L], b[L], visit[L], visited;
void dfs(int vertex, int parent = -1)
{
	visit[vertex] = 1;
	visited++;
	trace(adj[vertex], x)
	{
		if(x == parent)continue;
		if(visit[x])
		{
			cout<<"NO\n";
			exit(0);
		}
		dfs(x, vertex);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	std::vector<pii> v;
	set<pii>stor;
	FOR(i,1,n+1)
	{
		cin >> a[i] >> b[i];
		v.pb({a[i], i});
		v.pb({b[i], -i});
	}
	sort(all(v));
	int edge = 0;
	trace(v, x)
	{
		if(edge >= n)break;
		if(x.S < 0)
		{
			stor.erase({-a[-x.S], -x.S});
			trace(stor, y)
			{
				if(-y.F < a[-x.S])break;
				edge++;
				adj[y.S].pb(-x.S);
				adj[-x.S].pb(y.S);
			}
		}
		else stor.insert({-x.F, x.S});
	}
	dfs(1);
	if(edge == n-1 && visited == n)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}