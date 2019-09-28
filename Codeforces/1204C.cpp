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

const int L=1e2+7;
int co[L][L], dp[L][L];
int a[1000002];
void floyd(int n)
{
	FOR(i,1,n+1)
	{
		FOR(j,1,n+1)
		{
			FOR(k,1,n+1)
			{
				if(dp[j][k] < dp[j][i] + dp[i][k])continue;
				// if(dp[j][k] == dp[j][i] + dp[i][k])co[j][k]++;
				dp[j][k] = dp[j][i] + dp[i][k];
				co[j][k] += (co[j][i]*co[i][k]);
			}
		}
	}
}
string s[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	FOR(i,0,n)cin >> s[i];
	FOR(i,1,n+1)
		FOR(j,1,n+1)
			dp[i][j] = 100000;
	FOR(i,0,n)
	{
		dp[i+1][i+1] = 0;
		// co[i+1][i+1] = 1;
		FOR(j,0,n)
		{
			if(s[i][j] == '0')continue;
			dp[i+1][j+1] = 1;
			co[i+1][j+1] = 1;
		}
	}
	floyd(n);
	int m;
	cin>>m;
	FOR(i,0,m)cin >> a[i];
	std::vector<int> ans;
	ans.pb(a[0]);
	int prv = a[0];
	FOR(i,1,m-1)
	{
		if(dp[*ans.rbegin()][a[i]] < dp[prv][a[i]] + dp[*ans.rbegin()][prv] )
		{
			if(i==1)
			{
				prv =a[i];
				continue;
			}
			ans.pb(prv);
		}
		prv = a[i];
	}
	if(dp[*ans.rbegin()][a[m-1]] < dp[prv][a[m-1]] + dp[*ans.rbegin()][prv] )
	{
		if(m != 2)
		ans.pb(prv);
	}

	ans.pb(a[m-1]);
	cout<<sz(ans)<<ln;
	trace(ans,x)cout<<x<<" ";
	return 0;
}