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
ll h[L], dp[L], dp1[L];
void fff()
{
	ll n,a,r,m;
	cin >> n >> a >> r >> m;
	FOR(i,0,n)cin >> h[i];	
	sort(h,h+n);
	ll cur = 0;
	RFOR(i,n-2,0)
		dp[i] = dp[i+1] + (h[i+1]-h[i])*(n-i-1);
	FOR(i,1,100001)
		dp1[i] = dp1[i-1] + (h[i]-h[i-1])*i;
	ll ans = LLONG_MAX, mv, x,y, val = 0;
	FOR(i,0,n)
	{
		ans = min(ans, dp[i]*r+dp1[i]*a);
		mv = min(dp[i],dp1[i]);
		x = dp1[i]-mv;y=dp[i]-mv;
		ans = min(ans, y*r+x*a+mv*m);
		val += h[i];
	}
	val /= n;
	ll c1, c2;
	FOR(i,val-100,val+100)
	{
		c1 = c2 = 0;
		FOR(j,0,n)
		{
			if(h[j] <= i)c1 += (i-h[j]);
			else c2 += (h[j]-i);
		}
		ans = min(ans, c2*r+c1*a);
		mv = min(c1,c2);
		x = c1-mv;y=c2-mv;
		ans = min(ans, y*r+x*a+mv*m);
	}
	cout<<ans<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}