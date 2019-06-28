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

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=15;
int n, tim, po[L], a[L], b[L], m = 1e9 + 7;
ll dp[32769][226][3];
ll solve(int mask, int sofar, int prev)
{
	if(sofar==tim)return 1LL;
	if(sofar > tim)return 0LL;
	if(dp[mask][sofar][prev] != -1)return dp[mask][sofar][prev];
	dp[mask][sofar][prev] = 0;
	FOR(i,0,n)
	{
		if(b[i] == prev)continue;
		if(mask & po[i])continue;
		dp[mask][sofar][prev] = (dp[mask][sofar][prev] + solve(mask|po[i], sofar + a[i], b[i]))%m; 
	}
	return dp[mask][sofar][prev];
}
void pre()
{
	po[0] = 1;
	FOR(i,1,15)
	{
		po[i] = (po[i-1]*2);
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n >> tim;
		pre();
		FOR(i,0,n)
			cin >> a[i] >> b[i];
		FOR(i,0,32769)
			FOR(j,0,226)
				FOR(k,0,4)
					dp[i][j][k] = -1;
		cout<<solve(0,0,0);
		return 0;
}