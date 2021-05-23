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
const int L=5e3+7;
int n, xx = 0;
std::map<ll,int>co;
ll tot = 0, a[L];
ld dp[L][L], sum[L][L];
ld ans = 0;
ld solve(int l, int r)
{
	if(r == l)return dp[l][r] = 0;
	if(r == l+1)return dp[l][r] = a[l] + a[r];
	if(dp[l][r] != -1)return dp[l][r];
	ld &ret = dp[l][r];
	ret = 0;
	ld den = r-l;
	FOR(i,l,r)
	{
		ret += (solve(l,i) + solve(i+1,r) + sum[l][r])/den;
	}
	return ret;
}
void fff()
{
	xx++;
	co.clear();
	tot = 0;
	cin >> n;
	FOR(i,0,n)cin >> a[i];
	FOR(i,0,n)FOR(j,0,n)dp[i][j] = -1;
	FOR(i,0,n)
	{
		sum[i][i] = a[i];
		FOR(j,i+1,n)
    		sum[i][j] = sum[i][j-1] + a[j];
    }
	printf("Case #%d: %.10Lf\n",xx, solve(0,n-1) );
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