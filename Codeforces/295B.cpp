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

const int L=502;
ll a[L][L], x[L], dp[L][L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin >> n;
	 	FOR(i,1,n+1)FOR(j,1,n+1)cin >> a[i][j];
		FOR(i,0,n)cin >> x[i];
		std::vector<ll> ans;
		ll sofar = 0;
		FOR(i,1,n+1)FOR(j,1,n+1)dp[i][j] = INT_MAX;
		FOR(i,1,n+1)dp[i][i] = 0;
		std::vector<int> prev;
		int k;
		RFOR(i,n-1,0)
		{
			k = x[i];
			trace(prev, xx)
			{
				dp[k][xx] = a[k][xx];
				dp[xx][k] = a[xx][k];
			}
			FOR(i,1,n+1)
			{
				FOR(j,1,n+1)
				{
					dp[i][k] = min(dp[i][k], dp[i][j]+dp[j][k]);
					dp[k][i] = min(dp[k][i], dp[j][i]+dp[k][j]);
				}
			}
			sofar = 0;
			FOR(i,1,n+1)
			{
				FOR(j,1,n+1)
				{
					dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
					if(dp[i][j] != INT_MAX)
					sofar += dp[i][j];
				}
			}
			prev.pb(x[i]);
			ans.pb(sofar);
		}
		reverse(all(ans));
		trace(ans,x)cout<<x<< " ";
		return 0;
}