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
ll a[L], m = 1e9+7;
void fff()
{
	ll n, k;
	cin >> n >> k;
	FOR(i,0,n)cin >> a[i];	
	sort(a,a+n);
	if(a[0]>=0)
	{
		ll ans = 1;
		RFOR(i,n-1,n-k)
		{
			ans *= a[i];
			ans %=m;
		}
		cout << ans;
		return;
	}
	if(a[n-1] == 0 && (k&1))
	{
		cout << 0;
		return;
	}
	ll xx;
	if(a[n-1]<=0 && (k&1))
	{
		ll ans = 1;
		RFOR(i,n-1,n-k)
		{
			ans = (ans*a[i]);
			if(ans<0)
			{
				xx = abs(ans)/m;
				xx++;
				ans = (ans + xx*m)%m;
			}
			else ans %=m;
		}
		cout << ans<<ln;
		return;
	}
	ll ans = 1;
	if((k&1))
	{
		ans *= a[n-1];
		ans %=m;
		n--;
		k--;
	}
	ll l = 0, r = n-1;
	while(k>0)
	{
		if(a[l]*a[l+1]>a[r]*a[r-1])
		{
			ans *= a[l];
			if(ans<0)
			{
				xx = abs(ans)/m;
				ans = (ans + xx*m)%m;
			}
			else ans %=m;
			ans *= a[l+1];
			if(ans<0)
			{
				xx = abs(ans)/m;
				xx++;
				ans = (ans + xx*m)%m;
			}
			else ans %=m;
			l += 2;
			k-=2;
		}
		else
		{
			ans *= a[r];
			if(ans<0)
			{
				xx = abs(ans)/m;
				xx++;
				ans = (ans + xx*m)%m;
			}
			else ans %=m;
			ans *= a[r-1];
			if(ans<0)
			{
				xx = abs(ans)/m;
				xx++;
				ans = (ans + xx*m)%m;
			}
			else ans %=m;
			r -= 2;
			k-=2;	
		}
	}
	cout<<ans;
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