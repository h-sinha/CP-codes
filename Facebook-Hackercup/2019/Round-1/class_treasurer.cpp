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
ll m = 1e9 + 7, po[L], dp[L];
void pre()
{
	po[0] = 1;
	FOR(i,1,1000001)
	{
		po[i] = (po[i-1] * 2LL)%m;
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t, n, k;
	 	cin >> t;
	 	string s;
	 	pre();
	 	FOR(qq,1,t+1)
	 	{
	 		cin >> n >> k;
	 		cin >> s;
	 		FOR(i,0,n+1)dp[i] = 0;
	 		ll ans = 0;
	 		RFOR(i,n-1,0)
	 		{
	 			if(s[i] == 'A')dp[i] = -1-k;
	 			else dp[i] = 1-k;
	 			if(i!=n-1)
	 			{
	 				if(s[i] == 'A')
	 				{
	 					dp[i] = max(dp[i], dp[i+1] - 1);
	 				}
	 				else
	 				{
	 					dp[i] = max(dp[i], dp[i+1] + 1);
	 				}
	 			}
	 			if(dp[i] > 0)
	 			{
	 				s[i] = 'A';
	 				ans = (ans + po[i+1])%m;
	 				dp[i]-=2;
	 			}
	 		}
	 		cout<<"Case #"<<qq<<": "<<ans<<ln;
	 	}
		return 0;
}