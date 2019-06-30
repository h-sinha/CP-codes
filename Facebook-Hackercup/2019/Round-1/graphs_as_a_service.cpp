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

const int L=55;
int n, m, dp[L][L], from[1000000], to[1000000], wt[1000000];
void solve()
{
	FOR(i,1,n+1)
	{
		FOR(j,1,n+1)
		{
			FOR(k,1,n+1)
			{
				if(dp[j][i] == INT_MAX || dp[i][k] == INT_MAX)continue;
				if(j == k)continue;
				if(dp[j][i] + dp[i][k] < dp[j][k])dp[j][k] = dp[j][i] + dp[i][k];
			}
		}
	}
}
void init()
{
	FOR(i,0,52)FOR(j,0,52)dp[i][j] = INT_MAX;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t, x, y, z, f;
	 	cin >> t;
	 	FOR(qq,1,t+1)
	 	{
	 		cin >> n >> m;
	 		init();
	 		FOR(i,0,m)
	 		{
	 			cin >> x >> y >> z;
	 			dp[x][y] = z;
	 			dp[y][x] = z;
	 			from[i] = x, to[i] = y, wt[i] = z;
	 		}
	 		solve();
	 		f = 0;
	 		FOR(i,0,m)
	 		{
	 			if(dp[from[i]][to[i]] != wt[i] || dp[to[i]][from[i]] != wt[i])
	 			{
	 				f = 1;
	 				break;
	 			}
	 		}
	 		if(f)cout<<"Case #"<<qq<<": Impossible\n";
	 		else
	 		{
	 			cout<<"Case #"<<qq<<": "<<m<<ln;
	 			FOR(i,0,m)cout<<from[i]<<" "<<to[i]<<" "<<wt[i]<<ln;
	 		}
	 		
	 	}
		return 0;
}