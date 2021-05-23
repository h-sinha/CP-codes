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
int xx;
ll n, k, dp[L][2], m = 1e9 + 7, co;
string s;
ll solve(int x, int f)
{
	if(x >= (n+1)/2)
	{
		return (f+co) > 0;
	}
	if(dp[x][f] != -1)return dp[x][f];
	ll &ret = dp[x][f];
	ret = 0;
	int cur = s[x] - 'a';
	if(f)
	{
		ret = (k*solve(x+1, f))%m;
	}
	else
	{
		ret = (cur*solve(x+1, 1))%m;
		ret = (ret + (solve(x+1, f))%m)%m;
	}
	return ret;
}
void fff()
{
	xx++;
	cin >> n >> k;
	cin >> s;
	FOR(i,0,n)FOR(j,0,2)dp[i][j] = -1;
	string ss = "";
	FOR(i,0,(n+1)/2)ss += s[i];
	string ts = ss;
	if(n&1)ts = ts.substr(0,ts.size()-1);
	reverse(all(ts));
	ss += ts;
	co = (ss < s);
	cout << "Case #"<<xx<<": "<<solve(0, 0)<<ln;
}
int main()
{
	#ifdef LOCAL_EXEC
		freopen("in.txt", "r", stdin);
	 	freopen("out.txt", "w", stdout);
	#else	
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	#endif
	return 0;
}