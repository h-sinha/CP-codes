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
const int L=42;
string s[L];
int dp[L][L][L][L], a[L][L];
int get(int x1, int y1, int x2, int y2)
{
	int ret = a[x2][y2];
	if(x1)ret -= a[x1-1][y2];
	if(y1)ret -= a[x2][y1-1];
	if(x1 && y1)ret += a[x1-1][y1-1];
	return ret;
}
void fff()
{
	int n, m, q, aa, b, c, d;
	cin >> n >> m >> q;
	FOR(i,0,n)
	{
		cin >> s[i];
		FOR(j,0,m)a[i][j] = (s[i][j]-'0');
	}	
	FOR(i,1,n)
		FOR(j,0,m)
			a[i][j] += a[i-1][j];
	FOR(i,1,m)
		FOR(j,0,n)
			a[j][i] += a[j][i-1];
	FOR(i,0,n)
		FOR(j,0,m)
			FOR(k,i,n)
				FOR(l,j,m)
					if(get(i,j,k,l) == 0)
						dp[i][j][k][l] = 1;
	RFOR(i,n-2,0)FOR(j,0,m)FOR(k,i,n)FOR(l,j,m)dp[i][j][k][l] += dp[i+1][j][k][l];
	FOR(i,0,n)RFOR(j,m-2,0)FOR(k,i,n)FOR(l,j,m)dp[i][j][k][l] += dp[i][j+1][k][l];
	FOR(i,0,n)FOR(j,0,m)FOR(k,i,n)FOR(l,j,m)if(k)dp[i][j][k][l] += dp[i][j][k-1][l];
	FOR(i,0,n)FOR(j,0,m)FOR(k,i,n)FOR(l,j,m)if(l)dp[i][j][k][l] += dp[i][j][k][l-1];
	while(q--)
	{
		cin >> aa >> b >> c >> d;
		aa--, b--, c--, d--;
		cout<<dp[aa][b][c][d]<<ln;
	}
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