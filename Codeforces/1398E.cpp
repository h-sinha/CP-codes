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
const int L=1e6+7;
set<ll>big, fire, light;
map<ll,ll>type;
void fff()
{
	ll cur, n, t, d, cur1;
	ll ans = 0, tot = 0, f = 0, co = 0;
	cin >> n;
	while(n--)
	{
		cin >> t >> d;
		if(d<0)
		{
			ans += d;
			if(big.find(-d) != big.end())
			{
				big.erase(-d);
				co -= (1-type[-d]);
				ans += d;
				if(type[-d])tot--;
			}
			else 
			{
				if(t)light.erase(-d), tot--;
				else fire.erase(-d);
			}
		}
		else
		{
			ans += d;
			type[d] = t;
			if(t)light.insert(d), tot++;
			else fire.insert(d);
		}
		while(!big.empty() && !light.empty())
		{
			cur = *big.begin();
			cur1 = *light.rbegin();
			if(cur>cur1)break;
			light.erase(cur1);
			big.erase(cur);
			if(type[cur])light.insert(cur);
			else fire.insert(cur);
			co -= (1-type[cur]);
			big.insert(cur1);
			ans -= cur;
			ans += cur1;
		}
		while(!big.empty() && !fire.empty())
		{
			cur = *big.begin();
			cur1 = *fire.rbegin();
			if(cur>cur1)break;
			fire.erase(cur1);
			big.erase(cur);
			co -= (1-type[cur]);
			if(type[cur])light.insert(cur);
			else fire.insert(cur);
			big.insert(cur1);
			ans -= cur;
			ans += cur1;
			co++;
		}
		while(sz(big) > tot)
		{
			cur = *big.begin();
			co -= (1-type[cur]);
			big.erase(cur);
			ans -= cur;
			if(type[cur])light.insert(cur);
			else fire.insert(cur);
		}
		while(sz(big) < tot)
		{
			if(fire.empty() && light.empty())break;
			cur = cur1 = -1;
			if(!fire.empty())cur = *fire.rbegin();
			if(!light.empty())cur1 = *light.rbegin();
			if(cur > cur1)
			{
				ans += cur;
				fire.erase(cur);
				big.insert(cur);
				co++;
			}
			else
			{
				ans += cur1;
				light.erase(cur1);
				big.insert(cur1);
			}
		}
		if(!co && light.empty() && !big.empty())
		{
			cur = *big.begin();
			ans -= cur;
			big.erase(big.begin());
			light.insert(cur);
			if(!fire.empty())
			{
				co++;
				cur = *fire.rbegin();
				big.insert(cur);
				fire.erase(cur);
				ans += cur;
			}
		}
		cout << ans << ln;
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