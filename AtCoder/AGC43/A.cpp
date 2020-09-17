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
#define rall(c) c.rbegin(), c.rend()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
#define init(a, x) memset(a,x,sizeof(a))
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
 
const int L=1e2+7;
string s[L];
ll n, m, dp[L][L][2];
ll solve(int i, int j, int f)
{
	if(i == n-1 && j == m-1)
	{
		if(s[i][j] == '.')
		{
			return 0;
		}
		if(f)return 0;
		return 1;
	}
	if(i >= n || j>=m || i<0 || j<0)return 1e6; 
	if(dp[i][j][f] != -1)return dp[i][j][f];
	ll &ret = dp[i][j][f];
	ret = INT_MAX;
	if(f)
	{
		if(s[i][j] == '.')
		{
			// ret = 1 + min(solve(i+1,j,1-f),solve(i,j+1,1-f)) ;
			ret = min(solve(i+1,j,0),solve(i,j+1,0)) ;
		}
		else
		{
			ret = min(solve(i+1,j,1),solve(i,j+1,1)) ;
		}
	}
	else
	{
		if(s[i][j] == '#')
		{
			ret = 1 + min(solve(i+1,j,1),solve(i,j+1,1)) ;
		}
		else
		{
			ret = min(solve(i+1,j,f),solve(i,j+1,f)) ;
		}
	}
	return ret;
}
void ffs()
{
	cin >> n >> m;
	FOR(i,0,n)FOR(j,0,m)FOR(k,0,2)dp[i][j][k] = -1;
	FOR(i,0,n)
	{
		cin >> s[i];
	}	
	cout<<solve(0, 0, 0)<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	ffs();
	return 0;
}