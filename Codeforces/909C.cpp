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
#define sz(a)	ll(a.size())
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=5005;
ll n, m=1e9+7;
char s[L];
ll dp[L][L];
ll solve(int i, int f)
{
	if(i>n)return 1;
	if(dp[i][f] != -1)return dp[i][f];
	int cur = 0;
	if(s[i] == 'f')
	{
		if(f)
		{
			if(s[i-1]=='f')
			{
				if(s[i+1]=='f')cur = 1;
				dp[i][f] = solve(i+2, f+cur+1)%m;
			}
			else
			{
				dp[i][f] = 0;
				int cur = 0;
				if(s[i+1] == 'f')cur = 1;
				FOR(j,1,f+2)
				{
					dp[i][f] = (dp[i][f] + solve(i+2, j+cur))%m;
				}
			}
		}
		else
		{
			if(s[i+1]=='f')cur = 1;
			dp[i][f] = solve(i+2, f+cur+1)%m;
		}
	}
	else
	{
		if(f)
		{
			dp[i][f] = 0;
			if(s[i-1] == 'f')
			{
				dp[i][f] = solve(i+1,f);
			}
			else
			{
				FOR(j,0,f+1)
				{
					dp[i][f] = (dp[i][f] + solve(i+1, j))%m;
				}
			}
		}
		else dp[i][f] = solve(i+1, 0)%m;
	}
	return dp[i][f];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n;
	 	s[0] = 't';
	 	s[n+1] = 't';
	 	FOR(i,1,n+1)cin >> s[i];
	 	FOR(i,0,n+1)FOR(j,0,n+1)dp[i][j] = -1;
	 	cout<<solve(1,0)%m;
		return 0;
}