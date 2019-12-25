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
ll credit[L], debit[L];
struct node
{
	ll a, b, c;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	ll a, b, c, mn;
	cin >> n >> m;
	FOR(i,0,m)
	{
		cin >> a >> b >> c;
		debit[a] += c;
		credit[b] += c;
	}
	set<pii>SET;
	FOR(i,1,n+1)
		if(credit[i] - debit[i])
			SET.insert({credit[i] - debit[i], i});
	pii tmp, tmp1;
	std::vector<node> ans;
	while(!SET.empty())
	{
		tmp = *SET.begin();
		tmp1 = *SET.rbegin();
		mn = min(abs(tmp.F), abs(tmp1.F));
		ans.pb(node{tmp.S,tmp1.S,mn});
		SET.erase(tmp);
		SET.erase(tmp1);
		tmp.F += mn;
		tmp1.F -= mn;
		if(tmp.F)SET.insert(tmp);
		if(tmp1.F)SET.insert(tmp1);
	}
	cout<<sz(ans)<<ln;
	trace(ans,x)cout<<x.a<<" "<<x.b<<" "<<x.c<<ln;
	return 0;
}