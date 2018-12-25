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
int n, k;
ll even[L], odd[L], a[L];
ll e(int i)
{
	if(i >= n) return 0;
	if(even[i] != -1)return even[i];
	if(a[i]%2 != 0)return even[i] = e(i+1);
	else return even[i] = max(e(i+1), a[i] + e(i+k+1));
}
ll o(int i)
{
	if(i >= n) return 0;
	if(odd[i] != -1)return odd[i];
	if(a[i]%2 == 0)return odd[i] = o(i+1);
	else return odd[i] = max(o(i+1), a[i] + o(i+k+1));
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t;
	 	cin >> t;
	 	while(t--)
	 	{
	 		cin >> n >> k;
	 		FOR(i,0,n)cin >> a[i];
	 		FOR(i,0,n)even[i] = -1, odd[i] = -1;
	 		e(0);
	 		o(0);
	 		cout<<even[0] + odd[0]<<ln;
	 	}
		return 0;
}