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
map<ll,ll> counter;
pii ans[L];
ll a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n, mx = -1, t;
	 	ll tmp, tmp1;
	 	cin >> n >> t;
	 	deque<ll>q;
	 	FOR(i,0,n)
	 	{
	 		cin >> a[i];
	 		mx = max(mx, a[i]);
	 		q.push_back(a[i]);
	 	}
	 	ll cur = 1;
	 	std::vector<ll> v;
	 	while(1)
	 	{
	 		tmp = q.front();
	 		if(tmp == mx)break;
	 		q.pop_front();
	 		tmp1 = q.front();
	 		q.pop_front();
	 		if(tmp<tmp1)
	 		{
	 			q.push_front(tmp1);
	 			q.push_back(tmp);
	 		}
	 		else 
	 		{
	 			q.push_front(tmp);
	 			q.push_back(tmp1);
	 		}
	 		ans[cur] = {tmp,tmp1};
	 		cur++;
	 	}
	 	while(!q.empty())
	 	{
	 		v.pb(q.front());
	 		q.pop_front();
	 	}
	 	ll l;
	 	tmp = sz(v) - 1;
	 	FOR(i,0,t)
	 	{
	 		cin >> l;
	 		if(l<cur)cout<<ans[l].F<<" "<<ans[l].S<<ln;
	 		else
	 		{
	 			l-=cur;
	 			l%=tmp;
	 			cout<<mx<<" "<<v[l+1]<<ln;
	 		}

	 	}
		return 0;
}