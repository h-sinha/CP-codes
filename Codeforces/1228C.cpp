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
map<ll,ll> counter;
ll m = 1e9+7;
ll fastexpo(ll x,ll y)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
std::vector<ll> fact;
void find(ll n)
{
	ll tmp = sqrt(n);
	int f = 0;
	while (n%2 == 0) 
    { 
    	if(f==0)fact.pb(2);
    	f = 1;
        n = n/2; 
    } 
  	f = 0;
    for (ll i = 3; i <= tmp; i = i+2) 
    { 
    	f = 0;
        while (n%i == 0) 
        { 
        	if(f==0)fact.pb(i);
    		f = 1;
            n = n/i; 
        } 
    } 
    if(n>2)fact.pb(n);
  
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll x, n;
	cin >> x >> n;
	find(x);
	ll ans = 1;
	ll cur;
	trace(fact, y)
	{
		cur = y;
		while(cur<=n)
		{
			// debug(cur, y);
			ans = (ans * fastexpo(y,n/cur))%m;
			if(cur>n/y)break;
			cur *= y;
		}
	}
	cout<<ans;
	return 0;
}