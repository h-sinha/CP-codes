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

const int L=1507;
int n, m;
ll a[L][L], dp[L][L];
ll prv[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	FOR(i,1,n+1)
	{
		FOR(j,1,m+1)
		{
			cin >> a[i][j];
			a[i][j] += a[i][j-1];
		}
	}
	FOR(i,1,m+1)dp[n][i] = a[n][i];
	if(n % 2 == 1)
	{
		prv[m+1] = INT_MIN;
		RFOR(j,m,1)
		{
			prv[j] = max(prv[j+1], dp[n][j]);
		}
	}
	else
	{
		prv[0] = INT_MIN;
		FOR(j,1,m+1)
		{
			prv[j] = max(prv[j-1], dp[n][j]);
		}
	}
	RFOR(i,n-1,1)
	{
		FOR(j,1,m+1)
		{
			if(i&1)
			{
				dp[i][j] = a[i][j] + prv[j-1];
			}	
			else
			{
				dp[i][j] = a[i][j] + prv[j+1];
			}
		}
		if(i&1)
		{
			prv[m+1] = INT_MIN;
			RFOR(j,m,1)
			{
				prv[j] = max(prv[j+1], dp[i][j]);
			}
		}
		else
		{
			prv[0] = INT_MIN;
			FOR(j,1,m+1)
			{
				prv[j] = max(prv[j-1], dp[i][j]);
			}
		}
	}
	ll ans = LLONG_MIN;
	FOR(i,1,m+1)ans = max(ans, dp[1][i]);
	cout<<ans;
	return 0;
}