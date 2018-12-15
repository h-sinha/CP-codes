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
const int L=5e5+7;
string s;
std::vector<bool> visit(L);
int tim = 0, endTime[L], startTime[L], maxDepth, dp[L][26], co[26];
std::vector<int> depth[L], depthTime[L], cumSum[L][26], v[L];
void dfs(int vertex, int dpt)
{
	if(visit[vertex])return;
	// debug(vertex);
	startTime[vertex] = tim++;
	depth[dpt].pb(vertex);
	visit[vertex] = 1;
	depthTime[dpt].pb(tim-1);
	maxDepth = max(maxDepth, dpt);
	trace(v[vertex], x)
	{
		dfs(x, dpt+1);
	}
	endTime[vertex] = tim-1;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int n, m, a, h, st, en;
		cin >> n >> m;
		FOR(i,2,n+1)
		{
			cin >> a;
			v[a].pb(i);
			v[i].pb(a);
		}
		cin >> s;
		int odd = 0;
		dfs(1, 1);
		// debug(s);
		FOR(i, 1, maxDepth + 1)
		{
			FOR(j, 0, sz(depth[i]))
			{
				dp[j][s[depth[i][j] - 1] - 'a']++;
				if(!j)continue;
				FOR(k,0,26)
					dp[j][k] += dp[j-1][k];
			}
			FOR(j, 0, sz(depth[i]))
			{
				FOR(k,0,26)
				{
					cumSum[i][k].pb(dp[j][k]);
					dp[j][k] = 0;
				}
			}
		}
		int l, r, len;
		FOR(j,0,m)
		{
			cin >> a >> h;
			st = startTime[a], en = endTime[a];
			l = upper_bound(all(depthTime[h]), st-1) - depthTime[h].begin();
			r = upper_bound(all(depthTime[h]), en) - depthTime[h].begin() - 1;
			// debug(l,r);
			if(l>r)cout<<"Yes\n";
			else
			{
				odd = 0;
				FOR(i,0,26)
				{
					if(l)co[i] = cumSum[h][i][r] - cumSum[h][i][l-1];
					else co[i] = cumSum[h][i][r];
				}
				FOR(i,0,26)
				{
					if(co[i]&1)odd++;
					co[i] = 0;
				}
				len = r-l+1;
				if(odd==1 && len&1)cout<<"Yes\n";
				else if (len%2 ==0 && odd == 0)cout<<"Yes\n";
				else cout<<"No\n";
			}
			// debug(j);
		}
		// cout<<"dsa";
		return 0;
}