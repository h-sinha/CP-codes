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
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e6+7;
map<ll,ll> counter;
ll w[L], mx[L], ans;
std::vector<pii> v[L];
void dfs(int vertex, int parent)
{
	mx[vertex] = w[vertex];
	ll mx1=0, mx2=0, cur;
	trace(v[vertex], x)
	{
		if(x.F==parent)continue;
		dfs(x.F, vertex);
		if(mx[x.F]>x.S)
		{
			cur = w[vertex] + mx[x.F] - x.S;
			if(cur>=mx1)mx2=mx1, mx1=cur;
			else if(cur>=mx2)mx2=cur;
		}
	}
	mx[vertex]= max(mx[vertex], mx1);
	ans=max(ans, mx[vertex]);
	ans = max(ans, mx1+mx2-w[vertex]);
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	ll a, b, c;
	 	cin >> n;
	 	FOR(i,1,n+1)cin >> w[i];
	 	FOR(i,0,n-1)
	 	{
	 		cin >> a >> b >> c;
	 		v[a].pb(mp(b,c));
	 		v[b].pb(mp(a,c));
	 	}
	 	dfs(1,-1);
	 	cout<<ans;
		return 0;
}