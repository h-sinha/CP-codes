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
ll fastexpo(ll x,ll y,ll m = 998244353)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp%m;
}
int ass[L];
std::vector<int> v[L];
std::vector<bool> visit(L);
ll mod = 998244353, eve, odd, f;
void dfs(int vertex, int prev)
{
	if(visit[vertex])
	{
		if(ass[vertex] != 1-prev)f=1;
		return;
	}
	visit[vertex] = 1;
	ass[vertex] = 1-prev;
	if(prev == 1)eve++;
	else odd++;
	trace(v[vertex], x)
	{
		dfs(x, 1-prev);
	}
	return;
}
ll po[L];
void pre()
{
	po[0] = 1;
	FOR(i,1,1000001)
	{
		po[i] = (po[i-1]*2)%mod;
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t,a,b,n,m;
	 	ll ans;
	 	cin >> t;
	 	pre();
	 	while(t--)
	 	{
	 		cin >> n >> m;
	 		FOR(i,1,n+1)
	 		{
	 			v[i].clear();
	 			visit[i] = 0;
	 		}
	 		FOR(i,0,m)
	 		{
	 			cin >>a >>b;
	 			v[a].pb(b);
	 			v[b].pb(a);
	 		}
	 		ans = 1, f=0;
	 		FOR(i,1,n+1)
	 		{
	 			if(!visit[i])
	 			{
		 			eve = 0, odd = 0;
	 				dfs(i, 0);
	 				ans = (ans%mod * (po[eve]+po[odd])%mod)%mod;
	 			}
	 		}
	 		if(f)cout<<"0\n";
	 		else cout<<ans<<ln;
	 	}
		return 0;
}