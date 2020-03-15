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
int c[L], tot, n, done[L];
string s;
std::vector<int> v[L];
int solve()
{
	int idx = -1, co = 0, ac = 0;
	FOR(i,0,n)
	{
		if(s[i] == '(' && (!done[i]))
		{
			co++;
			if(co <= c[i])idx = i, ac++;
		}
	}
	int c1 = 0;
	FOR(i,0,idx+1)
	{
		if(c1 == ac)break;
		if(s[i] == '(' && (!done[i]))
		{
			done[i] = 1;
			v[tot].pb(i);
			c1++;
		}
	}
	FOR(i,0,n)
	{
		if(s[i] == ')' && (!done[i]))c[i] = 1;
		else c[i] = 0;
	}
	RFOR(i,n-1,idx)
	{
		if(ac > 0 && s[i] == ')' && (!done[i]))
		{
			c[i] = 0;
			done[i] = 1;
			ac--;
			v[tot].pb(i);
		}
	}
	if(sz(v[tot]) == 0)return 0;

	RFOR(i,n-1,0)
	{
		c[i] += c[i+1];
	}
	sort(all(v[tot]));
	tot++;
	return 1;
}
void ffs()
{
	cin >> s;	
	 n = s.length();
	FOR(i,0,n)if(s[i] == ')')c[i]++;
	RFOR(i,n-1,0)c[i] += c[i+1];
	int ret = 1;
	while(ret)
	{
		ret = solve();
	}
	cout<<tot<<ln;
	FOR(i,0,tot)
	{
		cout<<sz(v[i])<<ln;
		trace(v[i], x)cout<<x+1<<" ";
		cout<<ln;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	ffs();
	return 0;
}