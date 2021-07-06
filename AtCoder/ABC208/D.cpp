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
const int L=402;
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
std::vector<pii> v[L];
ll dp[L][L];
void fff()
{
	int n, m;
	cin >> n >> m;
	ll a, b, c;
	FOR(i,0,n+1)FOR(j,0,n+1)dp[i][j] = INT_MAX;
	FOR(i,0,n+1)dp[i][i] = 0;
	FOR(i,0,m)
	{
		cin >> a >> b >> c;
		v[a].pb({b,c});
		dp[a][b] = c;
	}
	ll ans = 0;
	// k
	FOR(i,1,n+1)
	{
		
		FOR(j,1,n+1)
		{
			FOR(k,1,n+1)
			{
				if(dp[j][k] > dp[j][i] + dp[i][k])
				{
					dp[j][k] = dp[j][i] + dp[i][k];
				}
			}
		}
		FOR(j,1,n+1)
		{
			FOR(k,1,n+1)
			{
				if(dp[j][k] != INT_MAX)
				{
					ans += dp[j][k];
				}
			}
		}
	}
	cout << ans << ln;
}
int main()
{
	#ifdef LOCAL_EXEC
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#else	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	#endif
	return 0;
}