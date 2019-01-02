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
int n, a[L];
string s, org;
ll dp[L][5];
ll solve(int i, int sofar)
{
	if(i>=n)return 0;
	if(sofar != -1 && dp[i][sofar] != -1)return dp[i][sofar];
	if(s[i] == org[sofar + 1])
	{
		if(sofar < 2)
			return dp[i][sofar] = min(solve(i+1,sofar + 1), solve(i+1, sofar) + a[i]);
		else
			return dp[i][sofar] = solve(i+1, sofar) + a[i];
	}
	else return dp[i][sofar] = solve(i+1, sofar);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n;
	 	cin >> s;
	 	org = "hard";
	 	FOR(i,0,n)FOR(j,0,4)dp[i][j] = -1;
	 	FOR(i,0,n)cin >> a[i];
		cout<<solve(0,-1);
		// FOR(i,0,n)FOR(j,0,4)debug(i,j,dp[i][j]);
		return 0;
}