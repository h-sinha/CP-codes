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
int n,a[L];
int dp[L][5], ans = -1;
int  solve(int i, int j)
{
	// debug(i,j);
	if(ans != -1)return 0;
	if(i>=n)
	{
		ans = 1;
		return 1;
	}
	if(dp[i][j]!=-1)return dp[i][j];
	if(a[i+1]>a[i])
	{
		FOR(k,j+1,6)dp[i][j] = max(dp[i][j],solve(i+1,k ));
		if(j==5)return 0;
	}
	else if(a[i+1]<a[i])
	{
		RFOR(k,j-1,1)dp[i][j] = max(dp[i][j],solve(i+1,k ));
		if(j==1)return 0;
	}
	else
	{
		FOR(k,1,6)
		{
			if(k==j)continue;
			dp[i][j] = max(dp[i][j],solve(i+1,k ));
		}
	}
	return dp[i][j];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL),cout.tie(NULL);
	 	cin >> n;
	 	FOR(i,0,n)
	 	{
	 		cin >> a[i];
	 	}
	 	FOR(i,0,n)FOR(j,0,6)dp[i][j]=-1;
		FOR(i,1,6)
		{
			dp[0][i] = solve(0,i);
		}
		int f =0;
		FOR(i,1,6)
		{
			if(dp[n-1][i]==1)f=1;
		}
		if(ans == -1 || f == 0)
		{
			cout<<"-1";
			return 0;
		}
		FOR(i,0,n)
		{
			FOR(j,1,6)
			{
				if(dp[i][j] == 1)
				{
					cout<<j<<" ";
				}
			}
		}
		return 0;
}