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
#define sz(a)	int(a.size())
#define F first
#define S second
#define aint(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<int,int>
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

const int L=5e3+7;
std::vector<pii> v[L];
int n, m, t;
int a[L], b[L], wt[L], dp[L][L], nxt[L][L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> t;
	FOR(i,0,m)
		cin >> a[i] >> b[i] >> wt[i];
	FOR(i,0,n+1)FOR(j,0,n+1)dp[i][j] = 1e9+1;
	dp[1][1] = 0;
	FOR(i,2,n+1)
	{
		FOR(j,0,m)
		{
			if(dp[b[j]][i] > dp[a[j]][i-1] + wt[j])
			{
				dp[b[j]][i] = dp[a[j]][i-1] + wt[j];
				nxt[b[j]][i] = a[j];
			}
		}
	}
	int ans = 0;
	FOR(i,1,n+1)
		if(dp[n][i] <= t)
			ans = max(ans, i);
	cout << ans << ln;
	int cur = n, co = ans;
	std::vector<int> out;
	while(cur != 1)
	{
		out.pb(cur);
		cur = nxt[cur][co];
		co--;
	}
	cout << 1 <<" ";
	RFOR(i,sz(out)-1,0)cout << out[i]<<" ";
	return 0;
}