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

const int L=2e3+7;
ll m = 998244353;
int n, dp[L][L], sumis[L];
string s;
ll fastexpo(ll x,ll y)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
ll solve(int l, int r)
{
	if(l == r || l > r || r < 0 || r >= n || l < 0 || l >= n)return 0;
	if(dp[l][r] != -1)return dp[l][r];
	dp[l][r] = 0;
	if(s[l] != '(')dp[l][r] = solve(l+1, r);
	if(s[r] != ')')dp[l][r] = (dp[l][r] + solve(l, r-1))%m;
	if(s[l] != '(' && s[r] != ')')dp[l][r] = (dp[l][r] - solve(l+1, r-1) + m)%m;
	if(s[l] != ')' && s[r] != '(')
	{
		ll sum = sumis[r-1] - sumis[l];
		dp[l][r] = (dp[l][r] + solve(l+1, r-1) + fastexpo(2, sum))%m; 
	}
	return dp[l][r];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	n = s.length();
	FOR(i,0,n)
		if(s[i] == '?')
			sumis[i] = 1;
	FOR(i,1,n)sumis[i] += sumis[i-1];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			dp[i][j] = -1;
	cout<<solve(0, n-1);
	return 0;
}