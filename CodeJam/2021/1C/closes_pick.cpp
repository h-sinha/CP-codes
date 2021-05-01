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
#define eb emplace_back
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
map<ll,ll> counter;
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
ll dp[31][3], n, k, p[31];
ll solve(int x, int sofar)
{
	if(sofar > 2)return -1e15;
	if(x >= n || sofar == 2)
	{
		if(sofar < 2)return k - p[n-1];
		return 0;
	}
	if(dp[x][sofar] != -1)return dp[x][sofar];
	ll &ret = dp[x][sofar];
	ret = 0;
	if(x == 0)
	{
		ret = max(solve(x+1, sofar), p[x]-1 + solve(x+1, sofar + 1));
	}
	else
	{
		ll diff = p[x] - p[x-1]-1;
		ll cur = 0, cur1 = 0;
		cur1 = diff;
		cur = (diff + 1 )/ 2;
		ret = max(solve(x+1, sofar), cur + solve(x+1, sofar + 1));
		ret = max(ret, cur1 + solve(x+1, sofar + 2));
	}
	return ret;
}
void fff()
{
	ll x;
	cin >> n >> k;
	set<ll>SET;
	FOR(i,0,n)
	{
		cin >> p[i];
		SET.insert(p[i]);
	}
	n = 0;
	trace(SET,x)
	{
		p[n++] = x;
	}
	if(n == 1)
	{
		ld num = k - 1;
		ld deno = k;
		printf("%.10Lf\n", num/deno);
		return;
	}
	FOR(i,0,n+1)FOR(j,0,3)dp[i][j] = -1;
	ld num = solve(0, 0);
	ld den = k;
	printf("%.10Lf\n", num/den);
}
int main()
{
	#ifdef LOCAL_EXEC
		freopen("in.txt", "r", stdin);
	 	freopen("out.txt", "w", stdout);
	#else	
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	int t;cin >> t;
	FOR(i,1,t+1)
	{
		printf("Case #%d: ",i);
		fff();
	}
	#endif
	return 0;
}