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

const int L=2e4+7;
map<ll,ll> counter;
ll m = 1e9+7, ans = 1;
ll fastexpo(ll x,ll y,ll m=1e9+7)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
ll dp[102][L], n, k, inv[102];
void solve(ll i)
{
	dp[0][0] = 1;
	int co = 0;
	while(n > 0 && n % i == 0)n/=i, co++;
	FOR(j,1,co+1)dp[j][0] = (i * dp[j-1][0])%m;
	FOR(a,1,k+1)
	{
	 	FOR(b,0,co+1)
	 	{
	 		dp[b][a] = 0;
	 		FOR(c,0,b+1)dp[b][a] = (dp[b][a] + (dp[c][a-1] * inv[b + 1])%m)%m;
	 	}
	}
	ans = (ans * dp[co][k])%m;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n >> k;
	 	ll tmp = sqrt(n);
	 	FOR(i,1,101)inv[i] = fastexpo(i,m-2)%m;
	 	FOR(i,2,tmp + 1)
	 	{
	 		if(n%i)continue;
	 		solve(i);	
	 	}
	 	if(n > 1)solve(n);
	 	cout<<ans;
		return 0;
}