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

const int L=1e6+7;
int a[L],dp[L][3],n;
// int ans[L];
std::vector<int> ans(L,4);
int solve(int i, int prev)
{
	if(i>=n)return 0;
	int ret;
	if(dp[i][prev] != INT_MAX)return dp[i][prev];
	if(a[i] == prev)
	{
		FOR(id,0,3)
		{
			if(id == prev)continue;
			{
				ret = 1 + solve(i+1,id);
				if(dp[i][prev] > ret)
				{
					dp[i][prev] = ret;
					ans[i] = id;
				}
				// dp[i][prev] = min(dp[i][prev], 1 + solve(i+1,id ));
			}
		}
	}
	else
	{
		FOR(id,0,3)
		{
			if(id == prev)continue;
			if(a[i] != id)
			{
				ret = 1 + solve(i+1,id);
				if(dp[i][prev] > ret)
				{
					dp[i][prev] = ret;
					ans[i] = id;
				}
				// dp[i][prev] = min(dp[i][prev], 1 + solve(i+1,id ));
			}
			else 
			{
				ret = solve(i+1,id);
				if(dp[i][prev] > ret)
				{
					dp[i][prev] = ret;
					ans[i] = id;
				}
				// dp[i][prev] = min(dp[i][prev],  solve(i+1,id ));
			}
		}
	}
	return dp[i][prev];
}
int co;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s;
	 	cin >> n;
	 	cin >> s;
	 	FOR(i,0,n)
	 	{
	 		if(i!=n-1)
	 		{
	 			if(s[i] != s[i+1])continue;
	 			if(i+2 >n-1)
	 			{
	 				if(s[i] == s[i+1])
	 				{
	 					co++;
	 					if(s[i+1] == 'R')s[i+1] = 'G';
	 					else if(s[i+1] == 'G')s[i+1] = 'B';
	 					else if(s[i+1] == 'B')s[i+1] = 'R';
	 				}
	 			}
	 			else 
	 			{
	 				if(s[i] == s[i+1] && s[i+1] == s[i+2])
	 				{
	 					co++;
	 					if(s[i+1] == 'R')s[i+1] = 'G';
	 					else if(s[i+1] == 'G')s[i+1] = 'B';
	 					else if(s[i+1] == 'B')s[i+1] = 'R';
	 				}
	 				else if(s[i] == s[i+1])
	 				{
	 					co++;
	 					if(s[i+1] == 'R' && s[i+2] == 'B')s[i+1] = 'G';
	 					else if(s[i+1] == 'R' && s[i+2] == 'G')s[i+1] = 'B';
	 					else if(s[i+1] == 'G' && s[i+2] == 'R')s[i+1] = 'B';
	 					else if(s[i+1] == 'G' && s[i+2] == 'B')s[i+1] = 'R';
	 					else if(s[i+1] == 'B' && s[i+2] == 'G')s[i+1] = 'R';
	 					else if(s[i+1] == 'B' && s[i+2] == 'R')s[i+1] = 'G';
	 					else if(s[i+1] == 'R' && s[i+2] == 'R')s[i+1] = 'G';
	 					else if(s[i+1] == 'G' && s[i+2] == 'G')s[i+1] = 'B';
	 					else if(s[i+1] == 'B' && s[i+2] == 'B')s[i+1] = 'R';
	 				} 

	 			}
	 		}
	 	}
	 	cout<<co<<ln;
	 	cout<<s;
		// FOR(i,0,n)
		// {
		// 	if(s[i] == 'G')a[i] = 1;
		// 	else if(s[i] == 'B') a[i] = 2;
		// } 
		// FOR(i,0,n)FOR(j,0,3)dp[i][j] = INT_MAX;
		// if(s[0]=='R')
		// {
		// 	solve(0,0);
		// 	solve(0,1);
		// }
		// else if(s[0] == 'G')
		// {
		// 	solve(0,0);
		// 	solve(0,1);
		// }
		// else 
		// {
		// 	solve(0,0);
		// 	solve(0,2);
		// }
		// cout<<min(dp[0][0], min(dp[0][1], dp[0][2]))<<ln;
		// FOR(i,0,n)
		// {
		// 	if(ans[i] == 0)cout<<"R";
		// 	if(ans[i] == 1)cout<<"G";
		// 	if(ans[i] == 2)cout<<"B";
		// }
		return 0;
}
