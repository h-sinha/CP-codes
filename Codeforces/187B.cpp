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

const int L=62;
const int M=1e3+7;
int s, t, k;
int n, m, r;
ll dp[L][L][L], out[M][L][L];
void floyd()
{
	FOR(car, 0, m)
		FOR(mid, 0, n)
			FOR(i, 0, n)
				FOR(j, 0, n)
					dp[car][i][j] = min(dp[car][i][j], dp[car][i][mid] + dp[car][mid][j]);
}
void solve()
{
	FOR(i,0,1000)
		FOR(j,0,n)
			FOR(k,0,n)
				out[i][j][k] = LLONG_MAX;
	FOR(i,0,m)
		FOR(j,0,n)
			FOR(k,0,n)
				out[0][j][k] = min(out[0][j][k], dp[i][j][k]);

	FOR(changes,1,n)
    	FOR(mid,0,n)
    		FOR(i,0,n)
    			FOR(j,0,n)
					out[changes][i][j] = min(out[changes][i][j], out[changes - 1][i][mid] + out[0][mid][j]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> r;
	FOR(i,0,m)
		FOR(j,0,n)
			FOR(k,0,n)
				cin >> dp[i][j][k];
    floyd();
    solve();
	while(r--)
	{
		cin >> s >> t >> k;
		s--, t--;
		k = min(k,n-1);
		cout << out[k][s][t] << ln;
	}
	return 0;
}