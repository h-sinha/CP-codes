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
int req_d, subsize[L], h[L], depth[L], parent[L][22];
std::vector<int> v[L];
int dfs(int vertex = 1, int _parent = -1, int dpt = 0)
{
	int tmp;
	h[vertex] = vertex;
	depth[vertex] = dpt;
	parent[vertex][0] = -1;
	trace(v[vertex], x)
	{
		if(x != _parent)
		{
			tmp = dfs(x, vertex, dpt+1);
			if(subsize[x] + 1 > subsize[vertex])
			{
				subsize[vertex] = subsize[x] + 1;
				h[vertex] = tmp;
			}
		}
	}
	return h[vertex];
}
inline int find_node(int a, int dist)
{
	int index=0;
	while(dist>0)
	{
		if(dist&1)a=parent[a][index];
		dist>>=1;index++;
	}
	return a;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int a, b, n;
	 	cin >> n;
	 	FOR(i,0,n-1)
	 	{
	 		cin >> a >> b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	int qleft = 35;
	 	cout<<"d 1"<<endl;
	 	// fflush(stdout);
	 	cin >> req_d;
	 	dfs();
	 	FOR(j,1,18)
	 		FOR(i,1,n+1)
	 			if(parent[i][j-1] != -1)
	 			parent[i][j] = parent[parent[i][j-1]][j-1];
	 	
	 	int cur_vertex = 1, dpt, cur_dpt;
	 	while(qleft > 0)
	 	{
	 		if(req_d - depth[cur_vertex] <= qleft)break;
	 		qleft--;
	 		cout<<"s "<<cur_vertex<<endl;
	 		// fflush(stdout);
	 		qleft--;
	 		cin >> cur_vertex;
	 		cout << "d " << h[cur_vertex]<<endl;
	 		// fflush(stdout);
	 		cin >> dpt;
	 		cur_dpt = (depth[h[cur_vertex]] + req_d - dpt)/2;
	 		cur_vertex = find_node(h[cur_vertex], depth[h[cur_vertex]] - cur_dpt);
	 	}
	 	while(req_d != depth[cur_vertex])
	 	{
	 		cout<<"s "<<cur_vertex<<endl;
	 		// fflush(stdout);
	 		cin >> cur_vertex;
	 	}
	 	cout<<"! "<<cur_vertex<<endl;
		return 0;
}