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
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const ll L=1e6+7;
struct node
{
	ll x, y, weight,idx;
};
std::vector<node> v;
std::vector<pii> adj[L];
bool comp(node x, node y)
{
	return x.weight < y.weight;
}
ll parent[L], children[L], add[L];
ll find(ll x)
{
	if(parent[x] == x)return x;
	return parent[x] = find(parent[x]);
}
void merge(ll a, ll b)
{
	ll pa = find(a);
	ll pb = find(b);
	if(children[pa] > children[pb])
	{
		children[pb] += children[pa];
		parent[pa] = pb;
	}
	else
	{
		children[pa] += children[pb];
		parent[pb] = pa;
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, cur, a, b, c, d;
	cin >> n >> m;
	ll fr, to, wt;
	FOR(i,0,m)
	{
		cin >> a >> b >> c;
		if(i == 0)
		{
			fr = a, to = b, wt = c;
			continue;
		}
		v.pb(node{a,b,c,i});
	}
	sort(all(v), comp);
	FOR(i,1,n+1)parent[i] = i;
	FOR(i,0,m-1)
	{
		merge(v[i].x,v[i].y);
		if(find(fr) == find(to))
		{
			cout<<v[i].weight;
			return 0;
		}
	}
	cout<<1000000000;
	return 0;
}