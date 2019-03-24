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

const int L=1e6+7;
ll l[L], b[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n, k;
	 	cin >> n >> k;
	 	std::vector<pii> v;
	 	FOR(i,0,n)
	 	{
	 		cin >> l[i]>> b[i];
	 		v.pb(mp(b[i], l[i]));
	 	}
	 	sort(all(v));
	 	multiset<pii>run, rem;
	 	FOR(i,0,n)
	 	{
	 		rem.insert(mp(-l[i], b[i]));
	 	}
	 	ll sumis = 0;
	 	FOR(i,0,k-1)
	 	{
	 		if(rem.empty())break;
	 		run.insert(*rem.begin());
	 		sumis -= (*rem.begin()).F;
	 		rem.erase(rem.begin());
	 	}
	 	ll ans = 0;
		FOR(i,0,n)
	 	{
	 		if(run.find(mp(-v[i].S, v[i].F)) != run.end())
	 		{
	 			run.erase(run.find(mp(-v[i].S, v[i].F)));
	 			sumis -= v[i].S;
	 			if(!rem.empty())
	 			{
	 				run.insert(*rem.begin());
	 				sumis -= (*rem.begin()).F;
	 				rem.erase(rem.begin());
	 			}
	 			ans = max(ans, (sumis + v[i].S)*v[i].F);
	 		}
	 		else if(rem.find(mp(-v[i].S, v[i].F)) != rem.end())
	 		{
	 			rem.erase(rem.find(mp(-v[i].S, v[i].F)));
	 			ans = max(ans, (sumis + v[i].S)*v[i].F);
	 		}
	 	}	 	
	 	cout<<ans;
		return 0;
}