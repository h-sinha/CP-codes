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
#define eb emplace_back
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
int n, m, r[L], b[L];
int dp[L][L];
int solve(int x, int y)
{
	if(x >= n && y >= m)return 0;
	if(dp[x][y] != -1)return dp[x][y];
	if(y >= m) dp[x][y] = max(solve(x+1, y) + r[x], r[x]);
	else if(x >= n) dp[x][y] = max(solve(x, y+1) + b[y], b[y]);
	else 
	{
		dp[x][y] = max(solve(x+1, y) + r[x], solve(x, y+1) + b[y]);
		dp[x][y] = max(dp[x][y], r[x]);
		dp[x][y] = max(dp[x][y], b[y]);
	}
	// debug(x, y, dp[x][y]);
	return dp[x][y];
}
void fff()
{
	cin >> n;
	FOR(i,0,n)cin >> r[i];
	cin >> m;
	FOR(i,0,m)cin >> b[i];
	FOR(i,0,n+2)FOR(j,0,m+2)dp[i][j] = -1;
	cout << max(0,solve(0, 0)) << ln;
}
int main()
{
	#ifdef LOCAL_EXEC
	  freopen("in.txt", "r", stdin);
	  freopen("out.txt", "w", stdout);
	#else
	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
	#endif
	int t;cin >> t;while(t--)
	fff();
	return 0;
}
