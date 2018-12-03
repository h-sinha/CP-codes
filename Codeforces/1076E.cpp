#include<bits/stdc++.h>
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
const ll L=1e6+7;
ll ans[L],sub[L];
std::vector<ll> v[L];
std::vector<pii> sol[L];
void dfs(ll vertex, ll parent, ll depth, ll sofar)
{
	ll ss = sofar;
	trace(sol[vertex],x)
	{
		sub[depth + x.F + 1] += x.S;
		ss += x.S;
	}
	ss -= sub[depth];
	ans[vertex] = ss;
	trace(v[vertex], x)
		if(x!=parent)
			dfs(x,vertex,depth+1,ss);
	trace(sol[vertex],x)
		sub[depth + x.F + 1] -= x.S;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,m,x,y;
	 	ll vi,di,xi;
	 	cin >> n;
	 	FOR(i,0,n-1)
	 	{
	 		cin >> x >> y;
	 		v[x].pb(y);
	 		v[y].pb(x);
	 	}
	 	cin >> m;
	 	FOR(i,0,m)
	 	{
	 		cin >> vi >> di >> xi;
	 		sol[vi].pb(mp(min(di,n),xi));
	 	}
	 	dfs(1,-1,0,0);
	 	FOR(i,1,n+1)cout<<ans[i]<<" ";
		return 0;
}