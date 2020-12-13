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
const int L=507;
string s[L];
int dp[L][L];
int n, m;
ll cs(ll x, ll l, ll r)
{
	if(l == 0)return dp[x][r];
	return dp[x][r] - dp[x][l-1];
}
ll get(int x, int y)
{
	ll cur = 0, ret = 0;
	ll l = y, r = y, aux;
	ll cx = x, cy = y;
	while(x < n && l >= 0 && r<m)
	{
		aux = cs(x, l, r);
		if(aux != r-l+1)break;
		cur++;
		x++, l--, r++;
	}
	return cur;
}
void fff()
{
	cin >> n >> m;
	FOR(i,0,n)cin >> s[i];
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			if(s[i][j] == '*')dp[i][j] = 1;
			else dp[i][j] = 0;
		}
	}
	FOR(i,0,n)
	{
		FOR(j,1,m)dp[i][j] += dp[i][j-1];
	}
	ll ans = 0;
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			ans += get(i,j);
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
	#endif
	int t;cin >> t;while(t--)
	fff();
	return 0;
}