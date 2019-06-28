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
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const ll L=1e6+7;
ll a[L];
std::map<ll, ll> counter;
std::map<ll, ll> id;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n;
	 	cin >> n;
	 	FOR(i,0,n){cin >> a[i];id[a[i]] = i+1;}
	 	sort(a,a+n);
	 	FOR(i,1,n)counter[a[i] - a[i-1]]++;
		std::vector<ll> v;
		ll mx = -1;
		trace(counter,x)
		{
			mx = max(mx,x.S);
		}
		if(n>=3)
		{
			ll diff = a[2] - a[1];
			int ff = 0;
			FOR(i,3,n)
			{
				if(a[i] - a[i-1] != diff)
				{
					ff = 1;
					break;
				}
			}
			if(!ff)
			{
				cout<<id[a[0]];
				return 0;
			}
		}
		if(counter.size() == 1)
		{
			cout<<id[a[0]];
			return 0;
		}
		trace(counter,x)
		{
			if(mx != x.S)continue;
			ll idx = -1,no = 0, f = 0, prev = 0;
			FOR(i,1,n)
			{
				if(a[i] - a[i-1]!=x.F)
				{
					if(f == 1)
					{
						no = 1;
						break;
					}
					else
					{
						if(i+1>=n || a[i+1]-a[i-1]==x.F)
						{
							idx = i;
							i++;
							f=1;
						}
						else
						{
							no = 1;
							break;
						}
					}
				}
			}
			if(!no)
			{
				cout<<id[a[idx]];
				return 0;
			}
		}
		cout<<"-1";
		return 0;
}