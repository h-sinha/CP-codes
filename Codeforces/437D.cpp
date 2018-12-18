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

const int L=1e5+7;
struct node
{
	int x, y;
	ld wt;
};
ld a[L];
int parent[L], children[L];
std::vector<pii> v[L];
int findParent(int x)
{
	if(parent[x] == x)return x;
	return parent[x] = findParent(parent[x]);
}
void merge(int x, int y)
{
	int px = findParent(x), py = findParent(y);
	if(children[px] > children[py])
	{
		children[py] += children[px];
		parent[px] = py;
	}
	else
	{
		children[px] += children[py];
		parent[py] = px;
	}
	return;
}
class comp
{
	public:
    bool operator() (node x , node y)
    {
    	return x.wt < y.wt;
    }
};
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, m, x, y;
	 	cin >> n >> m;
	 	FOR(i,1,n+1)cin >> a[i];
	 	node tmp;
	 	priority_queue <node,vector<node>, comp> q;
		FOR(i,0,m)
		{
			cin >> x >> y;
			v[x].pb(mp(y, min(a[x], a[y])));
			v[y].pb(mp(x, min(a[x], a[y])));
			tmp.x = x, tmp.y = y, tmp.wt = min(a[x], a[y]);
			q.push(tmp);
		}
		ld sumis = 0;
		int px, py, co=0;
		FOR(i,1,n+1)parent[i] = i, children[i] = 1;
		while(!q.empty())
		{
			tmp = q.top();
			q.pop();
			px = findParent(tmp.x), py = findParent(tmp.y);
			if(px == py)continue;
			co++;
			sumis += (tmp.wt * children[px] * children[py]);
			merge(tmp.x, tmp.y);
			if(co == n-1)break;
		}
		printf("%.10Lf\n",((sumis*2.0)/ld(n))/ld(n-1)) ;
		return 0;
}