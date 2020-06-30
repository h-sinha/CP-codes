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
ll get(string s, ll a, ll n)
{
	ll x = 0, prod = 1, cur;
	FOR(i,0,n)
	{
		cur = s[i] - '0';
		prod *= cur;
		x = x*10 + cur;
	}
	if(x<a)return -1;
	return prod;
}
void fff()
{
	ll aa, bb;
	cin >> aa >> bb;
	string a = to_string(aa);	
	string b = to_string(bb);
	string cur;
	int n = b.length();
	ll mx = 0, ret;
	string ans = b;
	ret = get(b, aa, n);
	if(ret > mx)
	{
		mx = ret;
		ans = b;
	}
	FOR(i,0,n)
	{
		if(a[i] == '0')continue;
		cur = b;
		cur[i] = b[i] - 1;
		FOR(j,i+1,n)cur[j] = '9';
		ret = get(cur, aa, n);
		if(ret > mx)
		{
			mx = ret;
			ans = cur;
		}
	}	
	FOR(i,0,n-1)
	{
		cur[i] = '9';
		ret = get(cur, aa, i+1);
		if(ret > mx)
		{
			mx = ret;
			ans = cur.substr(0,i+1);
		}
	}
	cout<<ans<<ln;
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