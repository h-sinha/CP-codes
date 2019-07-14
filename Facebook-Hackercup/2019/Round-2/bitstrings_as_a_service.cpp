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
ll children[L], comp[L], parent[L], val[L];
ll component(ll x)
{
	if(parent[x] == x)return x;
	return parent[x] = component(parent[x]);
}
void merge(ll a, ll b)
{
	ll pa = component(a);
	ll pb = component(b);
	if(pa == pb)return;
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
	ll t, n, m, x, y;
	cin >> t;
	FOR(q,1,t+1)
	{
		cin >> n >> m;
		FOR(i,0,n)parent[i] = i, children[i] = 1;
		FOR(i,0,m)
		{
			cin >> x >> y;
			x--, y--;
			ll idx = x, co = 0;
			while(x + co <= (x+y)/2)
			{
				merge(x + co, y - co);
				co++;
			}
		}
		ll z = 0, cur, o = 0;
		set<ll>SET;
		std::vector<pii> v;
		FOR(i,0,n)
		{
			cur = component(i);
			if(SET.find(cur) != SET.end())continue;
			SET.insert(cur);
			v.pb({children[cur],cur});
		}
		sort(all(v));
		ll id = 0;
		cur = 0;
		RFOR(i,sz(v)-1,0)
		{
			if(cur<=0)
			{
				val[v[i].S] = 0;	
				cur += v[i].F;
			}
			else
			{
				val[v[i].S] = 1;
				cur -= v[i].F;
			}
		}
		cout<<"Case #"<<q<<": ";
		FOR(i,0,n)
			cout<<val[component(i)];
		cout<<ln;
	}
	return 0;
}