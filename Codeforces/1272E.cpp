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
std::vector<int> v[L];
int n, dp[L][2], a[L];
void solve(int f)
{
	queue<int>q;
	FOR(i,1,n+1)
	{
		dp[i][f] = INT_MAX;
		if(a[i]%2 == f)
		{
			dp[i][f] = 0;
			q.push(i);
		}
	}
	int tmp;
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		trace(v[tmp], x)
		{
			if(dp[x][f] > dp[tmp][f] + 1)
			{
				dp[x][f] = dp[tmp][f] + 1;
				q.push(x);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	FOR(i,1,n+1)
	{
		cin >> a[i];
		if(i + a[i] <= n)v[i+a[i]].pb(i);
		if(i - a[i] >= 1)v[i-a[i]].pb(i);
	}
	solve(0);
	solve(1);
	FOR(i,1,n+1)
	{
		if(dp[i][1-(a[i]%2)] == INT_MAX)cout<<-1<<" ";
		else cout<<dp[i][1-(a[i]%2)]<<" ";
	}
	return 0;
}