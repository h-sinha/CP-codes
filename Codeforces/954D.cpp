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
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
set<int> v[1002];
int depth[1002][2];
void bfs(int vertex, int flag)
{
	int tmp;
	queue <int> q;
	q.push(vertex);
	depth[vertex][flag] = 0;
	while(sz(q))
	{
		tmp = q.front();
		q.pop();
		trace(v[tmp], x)
		{
			if(depth[x][flag] > depth[tmp][flag] + 1)
			{
				depth[x][flag] = depth[tmp][flag] + 1;
				q.push(x);
			}
		}
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, m, s, t, a, b;
	 	cin >> n >> m >> s >> t;
	 	FOR(i,0,m)
	 	{
	 		cin >> a >> b;
	 		v[a].insert(b);
	 		v[b].insert(a);
	 	}
	 	FOR(i,0,n+1)FOR(j,0,2)depth[i][j] =INT_MAX;
	 	bfs(s, 0);
	 	bfs(t, 1);
	 	int dist = depth[t][0], ans = 0;
	 	// FOR(i,1,n+1)debug(i, depth[i][0], depth[i][1]);
	 	FOR(i,1,n+1)
	 	{
	 		FOR(j,i+1,n+1)
	 		{
	 			if(v[i].find(j) == v[i].end() && dist <= depth[i][0] + 1 + depth[j][1] && dist <= depth[j][0] + 1 + depth[i][1])ans++;
	 		}
	 	}
	 	cout<<ans;
		return 0;
}