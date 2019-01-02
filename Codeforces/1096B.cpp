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
std::vector<int> mn(27,INT_MAX), mx(27, INT_MIN);
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s;
	 	ll f = 0, len, l, r;
	 	cin >> len;
	 	cin >> s;
	 	len = s.length();
	 	FOR(i,0,len)
	 	{
	 		FOR(j,0,26)
	 		{
	 			if((s[i]-'a') == j)continue;
	 			mn[j] = min(mn[j], i);
	 			mx[j] = max(mx[j], i);
	 		}
	 	}
	 	ll ans = 0, m = 998244353; 
	 	FOR(i,0,26)
	 	{
	 		if(mx[i] == INT_MIN)
	 		{
	 			cout<<((len*(len-1))/2)%m;
	 			return 0;
	 		}
	 		r = (len - mx[i] - 1);
	 		l = (mn[i] - 0);
	 		if(l == 0 && r == 0)continue;
	 		f = 1;
	 		ans = (ans + (r+1)*(l+1) - 1 + m)%m;
	 	}
	 	if(f)ans = (ans+1)%m;
	 	cout<<ans;
		return 0;
}