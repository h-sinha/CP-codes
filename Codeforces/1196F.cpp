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
std::vector<pair<int,ll>> v[L];
std::map<pii, ll> dist;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k, a, b, c;
	cin >> n >> m >> k;
	set<pair<ll, pii> >SET;
	FOR(i,0,m)
	{
		cin >> a >> b >> c;
		v[a].pb({b, c});
		v[b].pb({a, c});
		dist[{a,b}] = c;
		dist[{b,a}] = c;
		SET.insert({c, {a, b}});
		SET.insert({c, {b, a}});
	}
	pii nodes;
	ll cur, dd;
	std::map<pii, ll> :: iterator it;
	while(sz(SET) > 400)SET.erase(*SET.rbegin());
	while(!SET.empty())
	{
		dd = (*SET.begin()).F;
		nodes = (*SET.begin()).S;
		SET.erase(SET.begin());
		if(dist[{nodes.F, nodes.S}] != dd)continue;
		if(nodes.F<nodes.S)k--;
		if(!k)
		{
			cout << dd;
			return 0;
		}
		trace(v[nodes.F], x)
		{
			cur = dd + x.S;	
			it = dist.find({nodes.S, x.F});
			if(it == dist.end())
			{
				dist[{nodes.S, x.F}] = cur;
				dist[{x.F, nodes.S}] = cur;
				SET.insert({cur, {nodes.S, x.F}});
				SET.insert({cur, {x.F, nodes.S}});
			}
			else if((*it).S > cur)
			{
				SET.erase({(*it).S, {nodes.S, x.F}});
				SET.erase({(*it).S, {nodes.S, x.F}});
				dist[{nodes.S, x.F}] = cur;
				dist[{x.F, nodes.S}] = cur;
				SET.insert({cur, {nodes.S, x.F}});
				SET.insert({cur, {x.F, nodes.S}});
			}
		}
		while(sz(SET) > 400)SET.erase(*SET.rbegin());
	}
	return 0;
}