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
const int L=1e3+7;
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
int n, xx, X, Y, dp[L][3];
string s;
int solve(int x, int prv)
{
	if(x >= n)return 0;
	if(dp[x][prv] != -1e6)return dp[x][prv];
	int &ret = dp[x][prv];
	ret = 1e6;
	if(s[x] == '?')
	{
		if(prv == 0)
		{
			ret = min(ret, solve(x+1, 1));
			ret = min(ret, solve(x+1, 2));
		}
		else if(prv == 1)
		{
			ret = min(ret, solve(x+1, 1));
			ret = min(ret, X + solve(x+1, 2));	
		}
		else
		{
			ret = min(ret, Y + solve(x+1, 1));
			ret = min(ret, solve(x+1, 2));
		}
	}
	else
	{
		if(s[x] == 'J')
		{
			if(prv == 1)ret = X + solve(x+1, 2);
			else ret = solve(x+1, 2);
		}
		else if(s[x] == 'C')
		{
			if(prv == 2)ret = Y + solve(x+1, 1);
			else ret = solve(x+1, 1);
		}
		else
		{
			ret = solve(x+1, 0);
		}
	}
	return ret;
}
void fff()
{
	xx++;
	cin >> X >> Y >> s;
	n = sz(s);
	FOR(i,0,n)FOR(j,0,3)dp[i][j] = -1e6;
	cout << "Case #"<<xx<<": "<<solve(0,0)<<ln;
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