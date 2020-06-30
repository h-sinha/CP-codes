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
string s;
ll n, dp[11][11][2];
ll solve(int pos,int num, int f)
{
	int mx = s[pos] - '0';
	if(f == 0 && mx<num)return 0;
	if(pos>=n-1)
	{
		if(dp[pos][num][f] == -1)dp[pos][num][f] = 0;
		dp[pos][num][f]++;
		return 1;
	}
	if(dp[pos][num][f] != -1)return dp[pos][num][f];
	ll &ret = dp[pos][num][f];
	ret = 0;
	int tf = 0;
	mx = s[pos+1]-'0';
	FOR(i,0,10)
	{
		if(f)tf = 1;
		else if(f == 0 && i<mx)tf = 1;
		else tf =0;
		ret += solve(pos+1,i,tf);
	}
	return ret;
}
void fff()
{
	ll a, b, ans = 0;
	cin >> a >> b;
	if(a == -1)exit(0);
	s = to_string(b);
	n = s.length();
	init(dp,-1);
	FOR(i,0,10)
	{
		if(i<s[0]-'0')solve(0,i,1);
		else solve(0,i,0);
	}
	FOR(i,0,n)
		FOR(j,1,10)
			FOR(k,0,2)
				if(dp[i][j][k]>0)
				{
					debug(i,j,k,dp[i][j][k]);
					ans += (j*dp[i][j][k]);
				}
	if(a > 1)
	{
		s = to_string(a-1);
		n = s.length();
		init(dp,-1);
		FOR(i,0,n)
			FOR(j,1,10)
				FOR(k,0,2)
					if(dp[i][j][k]>0)
						ans -= (j*dp[i][j][k]);
	}
	cout<<ans<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(1)fff();
	return 0;
}