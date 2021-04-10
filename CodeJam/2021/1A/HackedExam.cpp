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
const int L=1e6+7;
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
int sc[L],n, q, po[L];
string a[3];
std::vector<int> v;
int xyx = 0;
void check(int x)
{
	std::vector<int> cur(n);
	FOR(i,0,n)
	{
		FOR(j,0,q)
		{
			if((x&po[j]))
			{
				if(a[i][j] == 'T')cur[i]++;
			}
			else
			{
				if(a[i][j] == 'F')cur[i]++;
			}
		}
	}
	FOR(i,0,n)
	{
		// debug(x, cur[i],sc[i],i);
		if(cur[i] != sc[i])return;
	}
	// debug(x);
	v.pb(x);
}
int solve(int mask)
{
	int cur = 0;
	trace(v,x)
	{
		FOR(i,0,q)
		{
			if((x&po[i]) == (mask&po[i]))cur++;
		}
	}
	// debug(mask, cur);
	return cur;
}
void fff()
{
	xyx++;
	cin >> n >> q;
	assert(q<=10);
	v.clear();
	FOR(i,0,n)
	{
		cin >> a[i] >> sc[i];
	}
	int p = po[q];
	FOR(i,0,p)
	{
		check(i);
	}
	ll num = 0, den = sz(v), ret = 0, bin = -1, ans = -1;
	FOR(i,0,p)
	{
		ret = solve(i);
		if(ret > ans)
		{
			ans = ret;
			bin = i;
		}
	}
	// debug(bin);
	cout << "Case #"<<xyx<<": ";
	FOR(i,0,q)
	{
		if((bin&po[i]))cout << "T";
		else cout << "F";
	}
	cout << " ";
	ll g = __gcd(ans, den);
	ans /= g, den /= g;
	cout << ans <<"/"<<den<<ln;
}
int main()
{
	po[0] = 1;
	FOR(i,1,11)po[i] = (po[i-1] << 1);
	#ifdef LOCAL_EXEC
		freopen("in.txt", "r", stdin);
	 	freopen("out.txt", "w", stdout);
	#else	
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	#endif
	return 0;
}