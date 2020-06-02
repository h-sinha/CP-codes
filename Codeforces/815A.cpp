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
const int L=1e2+7;
int mn[L];
int solve(int a[L][L], int n, int m, int f = 0, int f1 = 0)
{
	std::vector<int> r,c;
	FOR(i,0,n)
	{
		mn[i] = INT_MAX;
		FOR(j,0,m)
			mn[i] = min(mn[i], a[i][j]);
		FOR(k,0,mn[i])r.pb(i);
		FOR(j,0,m)
			a[i][j] -= mn[i];
	}
	FOR(i,0,m)
	{
		mn[i] = INT_MAX;
		FOR(j,0,n)
			mn[i] = min(mn[i], a[j][i]);
		FOR(k,0,mn[i])c.pb(i);
		FOR(j,0,n)
		{
			a[j][i] -= mn[i];
			if(a[j][i]>0)
			{
				return INT_MAX;
			}
		}
	}
	if(f+f1 == 2)
	{
		cout<<sz(r)+sz(c)<<ln;
		trace(r,x)cout<<"col "<<x+1<<ln;
		trace(c,x)cout<<"row "<<x+1<<ln;
	}
	else if(f)
	{
		cout<<sz(r)+sz(c)<<ln;
		trace(r,x)cout<<"row "<<x+1<<ln;
		trace(c,x)cout<<"col "<<x+1<<ln;
	}
	return sz(r) + sz(c);
}
void fff()
{	
	int n, m;
	cin >> n >> m;
	int a[L][L], b[L][L], a1[L][L], b1[L][L];
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			cin >> a[i][j];
			a1[i][j] = a[i][j];
			b1[j][i] = a[i][j];
			b[j][i] = a[i][j];
		}
	}
	int ret = solve(a,n,m);
	int ret1 = solve(b,m,n);
	if(min(ret,ret1) == INT_MAX)
	{
		cout<<-1;
		return;
	}
	if(ret < ret1)solve(a1,n,m,1);
	else solve(b1,m,n,1,1);
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