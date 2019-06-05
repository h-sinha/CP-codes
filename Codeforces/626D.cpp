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
int a[L], co[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin >> n;
	 	FOR(i,0,n)
	 		cin >> a[i];
	 	sort(a,a+n);
	 	vector<int> v;
	 	FOR(i,0,n)
	 	{
	 		FOR(j,i+1,n)
	 		{
	 			v.pb(a[j]-a[i]);
	 		}
	 	}
	 	sort(all(v));
	 	std::vector<int> ::iterator it;
	 	ld num = 0, deno = pow(sz(v),3);
	 	FOR(i,0,sz(v))
	 	{
	 		FOR(j,i,sz(v))
	 		{
	 			it = upper_bound(all(v), v[i]+v[j]);
	 			// if(v[i]+v[j]==4)
	 			// debug(sz(v),i,j,v[i], v[j], sz(v) - (it-v.begin()));
	 			// if(it == v.end())continue;
	 			if(i==j)
	 			num += (sz(v)- (it-v.begin()));
	 			else
	 			num += 2.0*(sz(v)- (it-v.begin()));

	 		}
	 	}
	 	// debug(num,deno);
	 	printf("%.10Lf\n",num/deno);
		return 0;
}