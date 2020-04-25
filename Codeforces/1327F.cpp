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
ll l[L], r[L], x[L], c[L], z[L], dp[L];
void ffs()
{
	ll n, k, m;
	ll cur, ans = 1;
	ll mod = 998244353;
	cin >> n >> k >> m;
	FOR(i,0,m)
		cin >> l[i] >> r[i] >> x[i];
	FOR(bit,0,k)
	{
		cur = (1<<bit);
		FOR(i,0,n+1)
		{
			dp[i] = 0;
			z[i] = 0;
			c[i] = 0;
		}
		FOR(i,0,m)
		{
			if(cur&x[i])c[l[i]]++, c[r[i] + 1]--;
			else z[r[i]] = max(z[r[i]], l[i]);
		}
		FOR(i,1,n+2)
		{
			c[i] += c[i-1];
			z[i] = max(z[i], z[i-1]);
		}
		dp[0] = 1;
		FOR(i,1,n+2)
		{
			if(!c[i])
			{
				if(z[i-1] != 0)
					dp[i] = (dp[i-1] - dp[z[i-1] - 1] + mod)%mod;
				else
					dp[i] = dp[i-1];
			}
			if(i > n)break;
			dp[i] = (dp[i] + dp[i-1])%mod;
		}
		ans = (ans * dp[n+1])%mod;
	}
	cout<<ans<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	ffs();
	return 0;
}