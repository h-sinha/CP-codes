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
ll po[L], n, m;
pbds X;
ll find(string s)
{
	ll ret = 0;
	FOR(i,0,m)ret += (s[m-i-1]-'0')*po[i];
	return ret;
}
bool check(int x)
{
	ll tot = po[m] - n;
	ll sm = x - X.order_of_key(x);
	// debug(x,sm,tot,(tot-1)/2);
	return sm >= (tot-1)/2;
}
void fff()
{
	string s;
	cin >> n >> m;
	X.clear();
	FOR(i,0,n)
	{
		cin >> s;
		X.insert(find(s));
	}
	ll l = 0, r = po[m]-1, mid;
	while(l < r-1)
	{
		mid = (l+r)/2;
		// debug(l,r,mid);
		if(check(mid))r = mid;
		else l = mid;
	}
	while(X.find(r) != X.end())r++;
	RFOR(i,m-1,0)
	{
		if(r&po[i])cout<<"1";
		else cout<<"0";
	}
	cout<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	po[0] = 1;
	FOR(i,1,61)po[i] = po[i-1]*2LL;
	int t;cin >> t;while(t--)
	fff();
	return 0;
}