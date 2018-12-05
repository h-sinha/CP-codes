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
const int L=3e5+7;
std::vector<int> v[L];
string s;
int dp[L][26];
int indeg[L], ans = INT_MIN;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, m, a, b, tmp;
	 	cin >> n >> m;
	 	cin >> s;
	 	FOR(i,0,m)
	 	{
	 		cin >> a >> b;
	 		v[a].pb(b);
	 		indeg[b]++;
	 	}
	 	queue<int>q;
	 	FOR(i,1,n+1)
	 		if(indeg[i] == 0)
	 			q.push(i);
	 	int co = 0;
	 	while(sz(q))
	 	{
	 		tmp = q.front();
	 		dp[tmp][s[tmp-1]-'a']++;
	 		q.pop();
	 		trace(v[tmp], x)
	 		{
	 			indeg[x]--;
	 			FOR(i,0,26)dp[x][i] = max(dp[tmp][i], dp[x][i]);
	 			if(indeg[x]==0)
	 			q.push(x);
	 		}
	 		co++;
	 	}
	 	FOR(i,0,n+1)FOR(j,0,26)ans = max(ans, dp[i][j]);
	 	if(co!=n)cout<<"-1";
	 	else cout<<ans;
		return 0;
}