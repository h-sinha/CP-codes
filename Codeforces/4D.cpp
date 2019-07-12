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
struct node
{
	int w, h, idx;
};
bool comp(node x, node y)
{
	if(x.w == y.w)return x.h < y.h;
	if(x.h == y.h)return x.w < y.w;
	return x.w < y.w;
}
int dp[L][2], n;
std::vector<node> v;
int solve(int i)
{
	if(i >= n)return 0;
	if(dp[i][0] != 0)return dp[i][0];
	int ret;
	dp[i][0] = 1;
	dp[i][1] = n;
	FOR(j,i+1,n)
	{
		if(v[i].w < v[j].w && v[i].h < v[j].h)
		{
			ret = 1 + solve(j);
			if(ret > dp[i][0])
			{
				dp[i][0] = ret;
				dp[i][1] = j;
			}
		}
	}
	return dp[i][0];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, h, a, b;
	cin >> n >> w >> h;
	FOR(i,0,n)
	{
		cin >> a >> b;
		v.pb(node{a,b,i});
	}
	sort(all(v), comp);
	int ans = 0, idx = n, ret;
	FOR(i,0,n)
	{
		if(v[i].w <= w || v[i].h <= h)continue;
		ret = solve(i);
		if(ret > ans)
		{
			ans = ret;
			idx = i;
		}
	}
	cout<<ans<<ln;
	while(idx < n)
	{
		cout<<v[idx].idx+1<<" ";
		idx = dp[idx][1];
	}
	return 0;
}