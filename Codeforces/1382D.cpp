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
const int L=4e2+7;
int p[L], dp[L][L], idx[L], m;
std::vector<int> co;
int solve(int i, int s)
{
	if(s < 0 || i >= m)return 0;
	if(s == 0)return 1;
	if(dp[i][s]!=-1)return dp[i][s];
	int &ret = dp[i][s];
	ret = solve(i+1,s) | solve(i+1, s-co[i]);
	return ret;
}
void fff()
{
	int n;
	cin >> n;
	FOR(i,0,2*n)FOR(j,0,2*n)dp[i][j] = -1;
	co.clear();
	FOR(i,0,2*n)
	{
		cin >> p[i];
		idx[p[i]] = i;
	}
	int prv = 2*n;
	RFOR(i,2*n,1)
	{
		if(idx[i] > prv)continue;
		co.pb(prv - idx[i]);
		prv = idx[i];
	}
	m = sz(co);
	cout << (solve(0,n) ? "YES\n":"NO\n");
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	return 0;
}