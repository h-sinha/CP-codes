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
ll a[L][2],dp[L][2], mod = 1e9 + 7, n, m;
ll fastexpo(ll x,ll y,ll m = 1e9 + 7)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
ll solve(int i, int f)
{
	if(i>=n)return f;
	if(dp[i][f] != -1)return dp[i][f];
	ll &ret = dp[i][f];
	ret = 0;
	if(a[i][0]*a[i][1])
	{
		if(a[i][0]>a[i][1] || f)ret = solve(i+1, 1);
		else if(a[i][0]<a[i][1])return 0;
		else ret = solve(i+1, 0);
	}
	else if(f)
	{
		int co = 0;
		if(!a[i][0])co++;
		if(!a[i][1])co++;
		ret = (ret + (fastexpo(m,co)*solve(i+1, 1))%mod)%mod;
	}
	else
	{
		if(a[i][0])
		{
			ret = (ret + ((a[i][0]-1)*solve(i+1, 1))%mod)%mod;
			ret = (ret + (solve(i+1, 0))%mod)%mod;
		}
		else if(a[i][1])
		{
			ret = (ret + ((m-a[i][1])*solve(i+1, 1))%mod)%mod;
			ret = (ret + (solve(i+1, 0))%mod)%mod;
		}
		else
		{
			ll aux = (m*(m-1)) / 2;
			aux %= mod;
			ret = (ret + (aux*solve(i+1, 1))%mod)%mod;
			ret = (ret + (m*solve(i+1, 0))%mod)%mod;
		}
	}
	return ret % mod;
}
void fff()
{
	int co = 0;
	cin >> n >> m;
	init(dp, -1);
	FOR(i,0,n)
	{
		cin >> a[i][0];
		co += (a[i][0] == 0);
	}
	FOR(i,0,n)
	{
		cin >> a[i][1];
		co += (a[i][1] == 0);
	}
	ll num = solve(0, 0);
	ll den = fastexpo(fastexpo(m, co), mod-2);
	cout<<(num*den)%mod;
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