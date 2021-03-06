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
int a[L];
std::map<int, int> co;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, f = 0, tot = 0;
	cin >> n;
	FOR(i,0,n)cin >> a[i];
	sort(a, a+n);
	FOR(i,0,n)
		co[a[i]]++;		
	trace(co, x)
	{
		if(x.F == 0 && x.S > 1)f = 1;
		else if(x.S >= 2)tot++;
		if(x.S > 2)f = 1;
		if(x.S >= 2 && co[x.F - 1] >= 1)f = 1;
	}
	if(tot > 1)f = 1;
	if(f)
	{
		cout<<"cslnb";
		return 0;
	}
	tot = 0;
	FOR(i,0,n)tot += (a[i] - i);
	if(tot&1)cout<<"sjfnb\n";
	else cout<<"cslnb\n";
	return 0;
}