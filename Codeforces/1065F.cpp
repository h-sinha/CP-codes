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

const int L=1e6+7;
int n, k;
int mxdist[L], ans[L], leaves[L], depth[L];
std::vector<int> v[L];
void assign_values(int vertex = 1, int _parent = 0)
{
	depth[vertex] = depth[_parent] + 1;
	mxdist[vertex] = INT_MAX;
	if(sz(v[vertex]) == 1 && vertex != 1)leaves[vertex]++, mxdist[vertex] = depth[vertex] - k;
	trace(v[vertex], x)
	{
		if(x!=_parent)
		{
			assign_values(x, vertex);
			if(mxdist[x] <= depth[vertex])
			{
				mxdist[vertex] = min(mxdist[vertex], mxdist[x]);
				leaves[vertex] += leaves[x];
			}
		}
	}
}
void solve(int vertex = 1, int _parent = -1)
{
	int ret = 0;
	if(sz(v[vertex]) == 1 && _parent != -1)ans[vertex]++;
	trace(v[vertex], x)
	{
		if(x != _parent)
		{
			solve(x, vertex);
			if(mxdist[x] <= depth[vertex])
				ans[vertex] = max(ans[vertex], ans[x] + leaves[vertex] - leaves[x]);
			else
				ans[vertex] = max(ans[vertex], ans[x] + leaves[vertex]);
		}
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int a;
	 	cin >> n >> k;
	 	FOR(i,2,n+1)
	 	{
	 		cin >> a;
	 		v[a].pb(i);
	 		v[i].pb(a);
	 	}
	 	assign_values();
	 	solve();
	 	cout<<ans[1];
	 	return 0;
}