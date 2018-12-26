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
std::vector<ll> v;
ll power[35];
void po()
{
	power[0] = 1;
	FOR(i,1,31)
	{
		power[i] = (power[i-1]*2);
	}
}
ll convert(int *arr, int len)
{
	ll num = 0;
	FOR(i,0,len+1)
	{
		if(arr[i])num += power[i];
	}
	return num;
}
void pre()
{
	po();
	int tmp, f;
	int arr[35];
	FOR(i,1,31)
	{
		tmp = 0;
		for (int j = 0; j < 31; j+=i)
		{

			f=0;
			FOR(k,j,j+i)
			{
				if(k >= 31)
				{
					f=1;
					break;
				}
				arr[k] = tmp;
			}
			if(!f && tmp)v.pb(convert(arr, j+i-1));
			tmp = 1-tmp;
		}
		tmp = 1;
		for (int j = 0; j < 31; j+=i)
		{
			FOR(k,j,j+i)
			{
				if(k >= 31)break;
				arr[k] = tmp;
			}
			if(tmp)v.pb(convert(arr, j+i-1));
			tmp = 1-tmp;
		}
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	pre();
	 	int t, l, r;
	 	cin >> t;
	 	sort(all(v));
	 	// trace(v, x)cout<<x<<" ";
	 	// cout<<endl;
	 	while(t--)
	 	{
	 		cin >> l >> r;
	 		cout<<(upper_bound(all(v), r)) - lower_bound(all(v), l)<<ln;
	 	}
		return 0;
}