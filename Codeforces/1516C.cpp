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
const int L=1e2+7;
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m=1e9+7)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
ll n,cur, a[L];
int dp[L][100001];
int solve(int x, int s)
{
	if(s == cur)return 1;
	if(s > cur)return 0;
	if(x == n)return 0;
	if(dp[x][s] != -1)return dp[x][s];
	int &ret = dp[x][s];
	ret = 0;
	ret |= solve(x+1, s);
	ret |= solve(x+1, s+a[x]);
	return ret;
}
void fff()
{
	cin >> n;
	ll s = 0;
	FOR(i,0,n)cin >> a[i], s += a[i];
	if(s & 1)
	{
		cout << 0 << ln;
		return;
	}
	cur = s/2;
	FOR(i,0,n)FOR(j,0,cur)dp[i][j] = -1;
	if(solve(0,0))
	{
		FOR(i,0,n)
		{
			if(a[i] & 1)
			{
				cout << 1 <<ln;
				cout << i+1 << ln;
				return;
			}
		}
		while(1)
		{
			FOR(i,0,n)
			{
				if(a[i] & 1)
				{
					cout << 1 <<ln;
					cout << i+1<<ln;
					return;
				}
				a[i] /= 2;
			}
		}
	}
	else
	{
		cout << 0 << ln;
		return;
	}

}
int main()
{
	#ifdef LOCAL_EXEC
		freopen("in.txt", "r", stdin);
	 	freopen("out.txt", "w", stdout);
	#else	
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	#endif
	return 0;
}