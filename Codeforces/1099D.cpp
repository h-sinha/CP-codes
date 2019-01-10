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
std::vector<int> v[L];
ll ans[L], s[L];
void dfs(int vertex, int parent = -1, ll sofar = 0)
{
	ll mn=INT_MAX;
	if(s[vertex] == -1)
	{
		mn = INT_MAX;
		trace(v[vertex],x)
		{
			if(x == parent)continue;
			mn = min(s[x],mn);
		}
		// debug(vertex, mn);
		if(mn != INT_MAX)
		{
			ans[vertex] = mn-sofar;
			sofar = mn;
		}
		else ans[vertex] = 0;
	}
	else
	{
		ans[vertex] = s[vertex] - sofar;
		sofar = s[vertex];
	}
	// debug(vertex, ans[vertex],sofar, mn);
	trace(v[vertex],x)
	if(x!=parent)dfs(x,vertex, sofar);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
 		int n,a ;
 		cin >> n;
 		FOR(i,2,n+1)
 		{
 			cin >> a;
 			v[a].pb(i);
 			v[i].pb(a);
 		}
 		FOR(i,1,n+1)cin >> s[i];
 		dfs(1);
 		FOR(i,1,n+1)
 		{
 			if(ans[i]<0)
 			{
 				cout<<"-1";
 				return 0;
 			}
 		}
 		ll out = 0;
 		FOR(i,1,n+1)out+=ans[i];
 		cout<<out;
		return 0;
}