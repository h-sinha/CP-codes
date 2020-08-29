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
const int L=2e2+7;
ll r[L], g[L], b[L], dp[L][L][L];
ll solve(int i, int j, int k)
{
	if(i<0||j<0||k<0)return -1e6;
	if((i==0 && j == 0)||(i==0 && k == 0)||(j==0&&k==0))return 0;
	ll &ret = dp[i][j][k];
	if(ret != -1)return dp[i][j][k];
	ret = solve(i-1,j-1,k) + r[i]*g[j];
	ret = max(ret, solve(i,j-1,k-1) + b[k]*g[j]);
	ret = max(ret, solve(i-1,j,k-1) + r[i]*b[k]);
	return ret;
}
void fff()
{
	ll nr, ng, nb;
	cin >> nr >> ng >> nb;
	FOR(i,1,nr+1)cin >> r[i];
	FOR(i,1,ng+1)cin >> g[i];
	FOR(i,1,nb+1)cin >> b[i];
	sort(r,r+nr+1);
	sort(g,g+ng+1);
	sort(b,b+nb+1);
	FOR(i,0,nr+1)FOR(j,0,ng+1)FOR(k,0,nb+1)dp[i][j][k]= -1;
	cout << solve(nr,ng,nb) << ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}