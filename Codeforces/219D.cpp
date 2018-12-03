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
const int L=2e5+7;
map<ll,ll> counter;
std::vector<pii> v[L];
int rev[L], depth[L], tr;
void dfs(int vertex, int parent, int reverse, int sofar)
{
	rev[vertex] = reverse;
	depth[vertex] = sofar;
	trace(v[vertex], x)
	{
		if(x.F != parent)
		{
			if(x.S == -1)dfs(x.F, vertex, reverse + 1, sofar + 1), tr++;
			else dfs(x.F, vertex, reverse, sofar + 1);
		}
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, a, b;
	 	cin >> n;
	 	FOR(i,0,n-1)
	 	{
	 		cin >> a >> b;
	 		v[a].pb(mp(b,1));
	 		v[b].pb(mp(a,-1));
	 	}
	 	FOR(i,1,n+1)tr += rev[i];
	 	dfs(1,-1, 0, 0);
	 	int cap, mn =INT_MAX;
	 	std::vector<int> ans;
		FOR(i,1,n+1)
			mn = min(mn, tr + depth[i] - 2*rev[i]);
		FOR(i,1,n+1)
		{
			if(mn == tr + depth[i] - 2*rev[i])ans.pb(i);
		}
		cout<<mn<<ln;
		trace(ans, x)cout<<x<<" ";
		return 0;
}