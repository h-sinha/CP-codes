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
const int L=1e6+7;
std::vector<int> v[L];
std::vector<int> cent;
int ss[L], n, depth[L], lst;
void dfs(int vertex, int parent = -1, int d = 0)
{
	ss[vertex] = 1;
	int f = 1;
	depth[vertex] = d;
	trace(v[vertex], x)
	{
		if(x != parent)
		{
			dfs(x, vertex, d + 1);
			ss[vertex] += ss[x];
			if(ss[x] > n/2)f = 0;
		}
	}
	if(ss[vertex] == 1)lst = vertex;
	if(n-ss[vertex] > n/2)f = 0;
	if(f)cent.pb(vertex);
}
int  cd, prv;
void dfs1(int vertex, int parent = -1, int d = 0)
{
	trace(v[vertex], x)
	{
		if(x != parent)
		{
			dfs1(x, vertex, d + 1);
		}
	}
	if(d>cd)
	{
		prv = parent;
		lst = vertex;
		cd = d;
	}
}
void fff()
{
	cin >> n;
	int a, b;
	FOR(i,0,n+1)
	{
		v[i].clear();
		ss[i] = 0;
	}
	cent.clear();
	FOR(i,0,n-1)
	{
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, -1);
	if(sz(cent) == 1)
	{
		FOR(i,1,n+1)
		{
			if(sz(v[i]))
			{
				cout << i <<" "<<v[i][0]<<ln;
				cout << i <<" "<<v[i][0]<<ln;
				return;
			}
		}
	}

	if(depth[cent[0]] > depth[cent[1]])swap(cent[0], cent[1]);
	int st = -1, mx = -1;
	trace(v[cent[0]], x)
	{
		if(x != cent[1] && depth[x] > mx)
		{
			mx = depth[x];
			st = x;
		}
	}
	cout << cent[0] <<" "<<st<<ln;
	cout << cent[1] <<" "<<st<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	return 0;
}