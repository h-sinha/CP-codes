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

const int L=2e2+7;
struct node
{
	int i, j, bal;
};
string s, t;
int n, m, dp[L][L][2*L];
node nxt[L][L][L];
char ans[L][L][L];
int solve(int i, int j, int bal)
{
	if(bal < 0 || bal > 200)return 1000;
	if(i == n && j == m)
	{
		nxt[i][j][bal] = {-1,-1,bal-1};
		if(bal > 0)ans[i][j][bal] = ')';
		else ans[i][j][bal] = '\n';
		return bal;
	}
	if(dp[i][j][bal] != -1)return dp[i][j][bal];
	int f =0, f1 = 0, prv;
	dp[i][j][bal] = 1000;
	if(i < n && s[i] == '(')f = 1;
	if(j < m && t[j] == '(')f1 = 1;
	if(f*f1)
	{
		prv = dp[i][j][bal];
		dp[i][j][bal] = min(dp[i][j][bal], 1+solve(i+1,j+1,bal+1));
		if(dp[i][j][bal] != prv)
		{
			nxt[i][j][bal] = {i+1,j+1,bal+1};
			ans[i][j][bal] = '(';
		}
	}
	else if(f)
	{
		prv = dp[i][j][bal];
		dp[i][j][bal] = min(dp[i][j][bal], 1+solve(i+1,j,bal+1));
		if(dp[i][j][bal] != prv)
		{
			nxt[i][j][bal] = {i+1,j,bal+1};
			ans[i][j][bal] = '(';
		}
	}
	else if(f1)
	{
		prv = dp[i][j][bal];
		dp[i][j][bal] = min(dp[i][j][bal], 1+solve(i,j+1,bal+1));
		if(dp[i][j][bal] != prv)
		{
			nxt[i][j][bal] = {i,j+1,bal+1};
			ans[i][j][bal] = '(';
		}
	}
	f = f1 = 0;
	if(i < n && s[i] == ')')f = 1;
	if(j < m && t[j] == ')')f1 = 1;
	if(f*f1)
	{
		prv = dp[i][j][bal];
		dp[i][j][bal] = min(dp[i][j][bal], 1+solve(i+1,j+1,bal-1));
		if(dp[i][j][bal] != prv)
		{
			nxt[i][j][bal] = {i+1,j+1,bal-1};
			ans[i][j][bal] = ')';
		}
	}
	else if(f)
	{
		prv = dp[i][j][bal];
		dp[i][j][bal] = min(dp[i][j][bal], 1+solve(i+1,j,bal-1));
		if(dp[i][j][bal] != prv)
		{
			ans[i][j][bal] = ')';
			nxt[i][j][bal] = {i+1,j,bal-1};
		}
	}
	else if(f1) 
	{
		prv = dp[i][j][bal];
		dp[i][j][bal] = min(dp[i][j][bal], 1+solve(i,j+1,bal-1));
		if(dp[i][j][bal] != prv)
		{
			ans[i][j][bal] = ')';
			nxt[i][j][bal] = {i,j+1,bal-1};
		}
	}
	prv = dp[i][j][bal];
	dp[i][j][bal] = min(dp[i][j][bal], 1+solve(i, j, bal - 1));
	if(dp[i][j][bal] != prv)
	{
		ans[i][j][bal] = ')';
		nxt[i][j][bal] = {i,j,bal-1};
	}
	prv = dp[i][j][bal];
	dp[i][j][bal] = min(dp[i][j][bal], 1+solve(i, j, bal + 1));
	if(dp[i][j][bal] != prv)
	{
		ans[i][j][bal] = '(';
		nxt[i][j][bal] = {i,j,bal+1};

	}
	return dp[i][j][bal];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> t;
	n = s.length();
	m = t.length();
	memset(dp, -1, sizeof(dp));
	solve(0,0,0);
	int i = 0, j = 0, bal = 0;
	node tmp;
	while(i != -1)
	{
		cout<<ans[i][j][bal];
		tmp = nxt[i][j][bal];
		i = tmp.i;
		j = tmp.j;
		bal = tmp.bal;
	}
	FOR(i,0,bal)cout<<")";
	return 0;
}