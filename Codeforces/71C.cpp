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
std::vector<int> co(L), v;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, tmp;
	 	cin >> n;
	 	FOR(i,0,n)
	 	{
	 		cin >> tmp;
	 		if(tmp)v.pb(i+1);
	 	}
	 	tmp = sqrt(n);
	 	for (int i = 1; i <= tmp ; ++i)
	 	{
	 		if(n % i)continue;
	 		trace(v, x)
	 		{
	 			if(n/i < 3)break;
	 			co[x%i]++;
	 		}
	 		FOR(j,0,i)
	 		{
	 			if(n/i < 3)break;
	 			if(co[j] >= n/i)
	 			{
	 				cout<<"YES\n";
	 				exit(0);
	 			}
	 		}
	 		fill(co.begin(), co.begin() + i, 0);
	 		trace(v, x)
	 		{
	 			if(i < 3)break;
	 			co[x%(n/i)]++;
	 		}
	 		FOR(j,0,n/i)
	 		{
	 			if(i < 3)break;
	 			if(co[j] >= i)
	 			{
	 				cout<<"YES\n";
	 				exit(0);
	 			}
	 		}
	 		fill(co.begin(), co.begin() + (n / i), 0);
	 	}
	 	cout<<"NO\n";
		return 0;
}