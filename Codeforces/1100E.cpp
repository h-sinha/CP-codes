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
const int L=1e5+7;
map<ll,ll> counter;
std::vector<pii> v[L];
int l, r, mid, tim, cycle, from[L], to[L], val[L], n, m;
std::vector<int> visit(L), out(L);
void dfs(int vertex)
{
	if(cycle)return;
	visit[vertex] = 1;
	trace(v[vertex], x)
	{
		
		if(val[x.S] <= mid)continue;
		else if(visit[x.F] == 1)
		{
			cycle = 1;
			return;
		}
		else if(!visit[x.F])
		{
			dfs(x.F);
		}
	}
	visit[vertex] = 2;
	out[vertex] = tim++;
}
bool check()
{
	cycle = 0;
	tim = 1;
	fill(visit.begin(), visit.begin() + n + 1, 0);
	FOR(i,1,n+1)
		if(!visit[i])
			dfs(i);
	return !cycle;
}
void ser()
{
	while(l<r -1)
	{
		mid=(l+r)/2;
		if(!check())
			l=mid ;
		else r=mid;
	}
	mid = r;
	if(!check())r = l;
	while(check() && r>=0)
	{
		r--;
		mid = r;
	}
	r++;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n >> m;
	 	int a, b, c;
	 	FOR(i,0,m)
	 	{
	 		cin >> a >> b >> c;
	 		v[a].pb(mp(b,i));
	 		val[i] = c;
	 		from[i] = a;
	 		to[i] = b;
	 		r = max(r, c);
	 	}
	 	ser();
	 	mid = r;
	 	cycle = 0, tim = 1;
	 	fill(visit.begin(), visit.begin() + n + 1, 0);
	 	FOR(i,1,n+1)
	 		if(!visit[i])
	 			dfs(i);
	 	std::vector<int> ans;
	 	FOR(i,0,m)
	 	{
	 		if(out[from[i]] < out[to[i]] && val[i] <= r)
	 			ans.pb(i+1);
	 	}
	 	cout<<r<<" "<<sz(ans)<<ln;
	 	trace(ans, x)cout<<x<<" ";
		return 0;
}