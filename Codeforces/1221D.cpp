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
ll a[L], b[L], dp[3][L], n;
ll solve(int i, int prv)
{
	if(i > n)return 0;
	if(dp[prv][i] != -1)return dp[prv][i]; 
	ll h = a[i-1] + prv;
	dp[prv][i] = 1e18 + 1;
	FOR(j,0,3)
	{
		if(h != a[i] + j)
		{
			dp[prv][i] = min(dp[prv][i], j * b[i] + solve(i+1, j));
		}
	}
	return dp[prv][i];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	while(q--)
	{
		cin >> n;
		memset(dp[0], -1, (n+1)*sizeof(ll));
		memset(dp[1], -1, (n+1)*sizeof(ll));
		memset(dp[2], -1, (n+1)*sizeof(ll));
		FOR(i,1,n+1)cin >> a[i] >> b[i];
		a[0] = -10;
		cout<<solve(1,0)<<ln;
	}
	return 0;
}