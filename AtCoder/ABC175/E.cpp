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
const int L=3e3+7;
ll dp[L][L][4], r, c, k, v[L][L];
ll solve(int x, int y, int co)
{
	// debug(co,x,y,r,c,dp[x][y][co]);
	if(co > 3)return -1e18;
	if(x>r || y>c)return -1e18;
	if(x == r && y == c)
	{
		if(co<3)return v[x][y];
		return 0;
	}
	ll &ret = dp[x][y][co];
	if(ret != -1)return ret;
	ret = 0;
	if(v[x][y])
	{
		if(co<3)
		{
			ret  = solve(x+1,y,0) + v[x][y];
			ret = max(ret, solve(x,y+1,co+1) + v[x][y]);
		}
		ret = max(ret, solve(x+1,y,0));
		ret = max(ret, solve(x,y+1,co));
	}
	else
	{
		ret = max(ret, solve(x+1,y,0));
		ret = max(ret, solve(x,y+1,co));
	}
	// debug(x, y, ret);
	return ret;
}
void fff()
{
	ll a, b, xx;
	cin >> r >> c >> k;
	FOR(i,0,k)
	{
		cin >> a >> b >> xx;
		v[a][b] = xx;
	}	
	FOR(i,1,r+1)FOR(j,1,c+1)FOR(k,0,4)dp[i][j][k] = -1;
	cout << solve(1,1,0) << ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}