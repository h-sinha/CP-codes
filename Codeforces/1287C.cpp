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

const int L=1e2+7;
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
int n, p[L], dp[L][L][L][2];
int solve(int i, int o, int e, int f=0)
{
	if(i>=n)return 0;
	if(dp[i][o][e][f]!=-1)return dp[i][o][e][f];
	int &ret = dp[i][o][e][f];
	ret = 1e6;
	if(i == 0)
	{
		if(p[i])ret = solve(i+1, o, e, p[i]&1);
		else 
		{
			if(e > 0)ret = min(ret, solve(i+1, o, e-1, 0));
			if(o > 0)ret = min(ret, solve(i+1, o-1, e, 1));
		}
		return ret;
	}
	if(p[i])
	{
		if(f == 1)
		{
			if(p[i]&1)ret = solve(i+1, o, e, 1);
			else ret = 1+solve(i+1, o, e, 0);
		}
		else
		{
			if(p[i]&1)ret = 1+solve(i+1, o, e, 1);
			else ret = solve(i+1, o, e, 0);
		}
	}
	else
	{	
		if(f == 0)
		{
			if(e > 0)ret = min(ret, solve(i+1, o, e-1, 0));
			if(o > 0)ret = min(ret, 1+solve(i+1, o-1, e, 1));
		}
		else
		{
			if(e > 0)ret = min(ret, 1+solve(i+1, o, e-1, 0));
			if(o > 0)ret = min(ret, solve(i+1, o-1, e, 1));
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int e=0, o=0;
	cin >> n;
	memset(dp, -1,sizeof(dp));
	FOR(i,0,n)
	{
		cin >> p[i];
		if(p[i])
		{
			if(p[i]&1)o++;
			else e++;
		}
	}
	int oo = n/2, ee = n/2;
	if(n&1)oo++;
	cout<<solve(0,oo-o,ee-e);
	return 0;
}