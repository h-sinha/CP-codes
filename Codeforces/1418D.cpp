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
map<ll,ll>co;
void fff()
{
	ll x, n, q, t;
	cin >> n >> q;
	set<ll>p;
	multiset<ll> gaps;
	FOR(i,0,n)
	{
		cin >> x;
		p.insert(x);
	}
	ll prv = -1;
	trace(p, x)
	{
		if(prv!=-1)gaps.insert(x-prv);
		prv = x;
	}
	ll ans = 0;
	if(sz(p) > 2)ans = *p.rbegin() - *p.begin() - *gaps.rbegin();
	cout << ans << ln;
	set<ll>::iterator it, it1, it2;
	while(q--)
	{
		cin >> t >> x;	
		if(t)
		{
			if(co[x]>0)co[x]++;
			else
			{
				p.insert(x);
				co[x]++;
				it = p.find(x);
				it1 = it, it2 = it;
				if(it1 != p.begin())it1--;
				it2++;
				if(it2 == p.end())it2--;
				if(it == it1)
				{
					if(it != it2)gaps.insert(*it2 - *it);
				}
				else if(it == it2)
				{
					if(it != it1)gaps.insert(*it - *it1);
				}
				else
				{
					gaps.erase(gaps.find(*it2-*it1));
					gaps.insert(*it2-*it);
					gaps.insert(*it-*it1);
				}
			}
		}	
		else
		{
			if(co[x]>1)co[x]--;
			else
			{
				co[x]--;
				it = p.find(x);
				it1 = it, it2 = it;
				if(it1 != p.begin())it1--;
				it2++;
				if(it2 == p.end())it2--;
				if(it == it1)
				{
					if(it != it2)gaps.erase(gaps.find(*it2 - *it));
				}
				else if(it == it2)
				{
					if(it != it1)gaps.erase(gaps.find(*it - *it1));
				}
				else
				{
					gaps.insert(*it2-*it1);
					gaps.erase(gaps.find(*it2-*it));
					gaps.erase(gaps.find(*it-*it1));
				}
				p.erase(x);
			}
		}
		if(sz(p) > 2)ans = *p.rbegin() - *p.begin() - *gaps.rbegin();
		else ans = 0;
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