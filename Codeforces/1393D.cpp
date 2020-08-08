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

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
const int L=2e3+7;
string s[L];
int u[L][L], d[L][L], l[L][L], r[L][L];
int n, m;
void fff()
{
	cin >> n >> m;
	FOR(i,0,n)cin >> s[i];
	FOR(i,0,n)
	{
		r[i][0] = 1;
		FOR(j,1,m)
		{
			r[i][j] = 1;
			if(s[i][j] == s[i][j-1])r[i][j]+=r[i][j-1];
		}
		l[i][m-1] = 1;
		RFOR(j,m-2,0)
		{
			l[i][j] = 1;
			if(s[i][j] == s[i][j+1])l[i][j]+=l[i][j+1];
		}
	}
	FOR(j,0,m)
	{
		u[0][j] = 1;
		FOR(i,1,n)
		{
			u[i][j] = 1;
			if(s[i][j] == s[i-1][j])u[i][j]+=min(u[i-1][j],min(l[i][j]-1, r[i][j]-1));
		}
		d[n-1][j] = 1;
		RFOR(i,n-2,0)
		{
			d[i][j] = 1;
			if(s[i][j] == s[i+1][j])d[i][j]+=min(d[i+1][j],min(l[i][j]-1, r[i][j]-1));
		}
	}
	int ans = 0;
	FOR(i,0,n)
		FOR(j,0,m)
			ans += min(u[i][j], d[i][j]);
	cout << ans<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//ll t;cin >> t;while(t--)
	fff();
	return 0;
}