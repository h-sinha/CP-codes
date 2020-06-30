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
map<ll,ll> counter;
ll a[L];
void fff()
{
	int n;
	cin >> n;
	FOR(i,0,n)cin >> a[i];
	ll f = 0, l = 1, cur = a[0], ans = 0;
	std::vector<int> v1,v2;
	v1.pb(a[0]);
	while(l<n)
	{
		if(f==0)
		{
			if(a[l]>a[l-1])l++;
			else
			{
				ans += abs(a[l-1]-cur);
				if(l-1)
				v1.pb(a[l-1]);
				cur = a[l];
				l++;
				f = 1;
			} 
		} 
		else 
		{
			if(a[l]<a[l-1])l++;
			else
			{
				ans += abs(a[l-1]-cur);
				if(l-1)
				v1.pb(a[l-1]);
				cur = a[l];
				l++;
				f = 0;
			} 

		}
	}	
	ans += (abs(a[n-1])-cur), v1.pb(a[n-1]);
	l = 1,f = 1, cur = a[0];
	ll aux = 0;
	v2.pb(a[0]);
	while(l<n)
	{
		if(f==0)
		{
			if(a[l]>a[l-1])l++;
			else
			{
				aux += abs(a[l-1]-cur);
				if(l-1)
				v2.pb(a[l-1]);
				cur = a[l];
				l++;
				f = 1;
			} 
		} 
		else 
		{
			if(a[l]<a[l-1])l++;
			else
			{
				aux += abs(a[l-1]-cur);
				if(l-1)
				v2.pb(a[l-1]);
				cur = a[l];
				l++;
				f = 0;
			} 

		}
	}	
	aux += (abs(a[n-1])-cur), v2.pb(a[n-1]);
	if(ans>aux)
	{
		cout<<sz(v1)<<ln;
		trace(v1,x)cout<<x<<" ";
		cout<<ln;
	}
	else if(ans<aux)
	{
		cout<<sz(v2)<<ln;
		trace(v2,x)cout<<x<<" ";
		cout<<ln;
	}
	else if(sz(v1)<sz(v2))
	{
		cout<<sz(v1)<<ln;
		trace(v1,x)cout<<x<<" ";
		cout<<ln;
	}
	else
	{
		cout<<sz(v2)<<ln;
		trace(v2,x)cout<<x<<" ";
		cout<<ln;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	return 0;
}