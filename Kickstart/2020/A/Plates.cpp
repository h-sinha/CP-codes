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

const int L=1807;
int xx;
ll n, k, p, dp[52][L], a[52][L];
ll solve(int x, int lft)
{
	if(x >= n)return 0;
	if(dp[x][lft] != -1)return dp[x][lft];
	ll &ret = dp[x][lft];
	ret = solve(x+1, lft);
	FOR(i,0,k)
	{
		if(lft < i+1)break;
		ret = max(ret, solve(x+1, lft - i -1) + a[x][i]);
	}
	return ret;
}
void ffs()
{
	xx++;
	cin >> n >> k >> p;
	FOR(i,0,n)
	{
		FOR(j,0,p+1)dp[i][j] = -1;
	}
	FOR(i,0,n)
	{
		FOR(j,0,k)
			cin >> a[i][j];
		FOR(j,1,k)a[i][j] += a[i][j-1];
			
	}
	cout<<"Case #"<<xx<<": "<<solve(0,p)<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin >> t;while(t--)
	ffs();
	return 0;
}