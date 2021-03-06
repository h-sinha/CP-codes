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
#define rall(c) c.rbegin(), c.rend()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
#define init(a, x) memset(a,x,sizeof(a))
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
int dp[L][4], xx, n, a[L];
int solve(int i=0, int f=0)
{
	if(i>=n)return 0;
	int &ret = dp[i][f];
	if(dp[i][f] != -1)return dp[i][f];
	ret = 1e7;
	if(i == 0)
	{
		ret = min(ret, solve(i+1,0));
		ret = min(ret, solve(i+1,1));
		ret = min(ret, solve(i+1,2));
		ret = min(ret, solve(i+1,3));
	}
	else
	{
		if(a[i]>a[i-1])
		{
			FOR(j,f+1,4)ret = min(ret, solve(i+1,j));
			FOR(j,0,f)ret = min(ret, 1+solve(i+1,j));
		}
		else if(a[i]<a[i-1])
		{
			RFOR(j,f-1,0)ret = min(ret, solve(i+1,j));
			FOR(j,f,4)ret = min(ret, 1+solve(i+1,j));
		}
		else
		{
			ret = solve(i+1,f);
			FOR(j,0,4)
			{
				if(j==f)continue;
				ret = min(ret, 1+solve(i+1,j));
			}
		}
	}
	return ret;
}
void fff()
{
	xx++;
	cin >> n;
	FOR(i,0,n)FOR(j,0,4)dp[i][j] = -1;
	FOR(i,0,n)cin >> a[i];
	cout <<"Case #"<<xx<<": "<<solve()<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	return 0;
}