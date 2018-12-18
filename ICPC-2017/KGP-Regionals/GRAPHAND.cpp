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

const ll L=1e5+7;
std::vector<pii> v[L];
ll val[L], cost[L], req;
ll s, t, n, m, k;
std::vector<ll> dist(L);
bool valid(ll x)
{
	return (val[x]&req) == req;
}
ll solve()
{
	fill(all(dist), LLONG_MAX);
	revpr q;
	q.push(mp(0LL, s));
	dist[s] = 0LL;
	pii tmp;
	while(!q.empty())
	{
		tmp = q.top();
		if(tmp.S == t) return dist[t]; 
		q.pop();
		trace(v[tmp.S], x)
		{

			if(!valid(x.S))continue;
			if(tmp.F + cost[x.S] < dist[x.F])
			{
				dist[x.F] = tmp.F + cost[x.S];
				q.push(mp(dist[x.F], x.F));
			}
		}
	}
	return LLONG_MAX;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n >> m;
	 	ll a,b,c,vv;
	 	ll ans = LLONG_MAX, mask = 0;
	 	FOR(i,0,m)
	 	{
	 		cin >> a >> b >> c >> vv;
	 		v[a].pb(mp(b,i));
	 		v[b].pb(mp(a,i));
	 		cost[i] = c, val[i] = vv;
	 	}
	 	cin >> s >> t >> k;
	 	RFOR(i,30,0)
	 	{
	 		if(k & (1<<i))
	 		{
	 			mask |= (1<<i);
	 			continue;
	 		}
	 		req = mask | (1<<i);
	 		ans = min(ans, solve());
	 	}
	 	req = k;
	 	ans = min(ans, solve());
	 	if(ans == LLONG_MAX)cout<<"-1";
	 	else cout<<ans;
		return 0;
}