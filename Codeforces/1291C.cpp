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

const int L=3507;
int dp[L][L], a[L], lft;
int solve(int l, int r)
{
	if(dp[l][r] != -1)return dp[l][r];
	if(r - l + 1 <= lft)return dp[l][r] = max(a[l], a[r]);
	return dp[l][r] = min(solve(l+1, r) , solve(l, r-1));
}
void ffs()
{
	int n, m, k, ans = INT_MIN;
	cin >> n >> m >> k;
	m--;
	k = min(k, m);
	lft = n - m;
	FOR(i,0,n)FOR(j,0,n)dp[i][j] = -1;
	FOR(i,0,n)cin >> a[i];
	FOR(i,0,n)FOR(j,0,n)dp[i][j] = solve(i, j);
	FOR(i,0,k+1)ans = max(ans, dp[i][n-k+i-1]);
	cout<<ans<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin >> t;while(t--)
	ffs();
	return 0;
}